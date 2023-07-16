//----------------Naive Approach---------------//
class Solution {
public:
    int dp[1<<16][64];
    int choice[1<<16][64];
    int req_mask,m;
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n=req_skills.size();
        m=people.size();
        unordered_map<string,int>Skills;
        for(int i=0;i<n;i++){
            Skills[req_skills[i]]=i;
        }
        vector<int>P;
        for(auto &i:people){
            int h=0;
            for(string &s:i){
                h=h|1<<Skills[s];
            }
            P.push_back(h);
        }
        req_mask=(1<<n)-1;
        memset(dp,-1, 1 << (n + 8));
        memset(choice,0, 1<< (n + 6));
        solve(P,0,0);
        vector<int>ans;
        int mask=0;
        for(int i=0;i<m;i++){
            if(choice[mask][i]){
                ans.push_back(i);
                mask|=P[i];
            }
            if(mask==req_mask) break;
        }
        return ans;

    }
    int solve(vector<int>& P,int i,int mask){
        if(mask==req_mask) return 0;
        if(i==m) return 1000;
        if(dp[mask][i]!=-1) return dp[mask][i];
        int Take=solve(P,i+1,mask|P[i])+1;
        int Skip=solve(P,i+1,mask);
        if(Take<Skip) choice[mask][i]=1;
        return dp[mask][i]=min(Take,Skip);
    }
};

//----------------Optimal Approach---------------//

class Solution {
public:
    
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n=req_skills.size();
        unordered_map<int,vector<int>>dp;
        dp.reserve(1<<n);
        dp[0]={};
        unordered_map<string,int>skill_index;
        for(int i=0;i<n;i++){
            skill_index[req_skills[i]]=i;
        }
        for(int i=0;i<people.size();i++){
            int curr_skills=0;
            for(auto &skill:people[i]){
                curr_skills |= 1<<skill_index[skill];
            }
            for(auto it=dp.begin();it!=dp.end();it++){
                int comb=it->first | curr_skills;
                if(dp.find(comb)==dp.end() || dp[comb].size()>1 + dp[it->first].size()){
                    dp[comb]=it->second;
                    dp[comb].push_back(i);
                }
            }
        }
        return dp[(1<<n)-1];
    }
};
