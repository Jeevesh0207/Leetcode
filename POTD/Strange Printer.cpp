class Solution {
public:
    int Solve(int i,int j,const string &s,vector<vector<int>>&dp){
        if(i==j) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MAX;
        for(int k=i;k<j;k++){
            ans=min(ans,Solve(i,k,s,dp)+Solve(k+1,j,s,dp));
        }
        return dp[i][j]=(s[i]==s[j])?ans-1:ans;
    }
    int strangePrinter(std::string s) {
        if(s.size()==0)return 0;
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return Solve(0,n-1,s,dp); 
    }
};
