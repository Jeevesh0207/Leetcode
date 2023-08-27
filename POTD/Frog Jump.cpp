class Solution {
public:
    bool solve(vector<int>& stones,int idx,int last,unordered_map<int,int> &mp,vector<vector<int>> &dp)
    {
        if(idx==stones.size()-1)
        return true;

        if(dp[idx][last]!=-1)
        return dp[idx][last];

        bool first=false,second=false,third=false;
        
        if(mp.find(stones[idx]+last-1)!=mp.end() and last!=1)
        {
            first=solve(stones,mp[stones[idx]+last-1],last-1,mp,dp);
        }

        if(mp.find(stones[idx]+last)!=mp.end())
        {
            second=solve(stones,mp[stones[idx]+last],last,mp,dp);
        }

        if(mp.find(stones[idx]+last+1)!=mp.end())
        {
            third=solve(stones,mp[stones[idx]+last+1],last+1,mp,dp);
        }

        return dp[idx][last]=first || second || third;
    }

    bool canCross(vector<int>& stones) {
        unordered_map<int,int> mp;

        int n=stones.size();
        vector<vector<int>> dp(n+1,vector<int>(20004,-1));

        for(int i=0;i<stones.size();i++)
        mp[stones[i]]=i;

        if(stones[1]!=1)
        return false;

        return solve(stones,1,1,mp,dp);  
    }
};
