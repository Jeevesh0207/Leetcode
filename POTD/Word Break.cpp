class Solution {
public:
    bool Solve(string s,unordered_set<string>&unst,int pos,vector<int>&dp){
        if(pos==s.size()) return true;  
        if(dp[pos]!=-1) return dp[pos];  
        for(int i=pos;i<s.size();i++){
            string sub=s.substr(pos,i-pos+1);
            if(unst.count(sub) && Solve(s,unst,i+1,dp)) {
                return dp[pos]=true;
            }
        }
        return dp[pos]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<int>dp(n,-1);
        unordered_set<string>unst;
        for(auto i:wordDict) unst.insert(i);
        return Solve(s,unst,0,dp);
    }
};
