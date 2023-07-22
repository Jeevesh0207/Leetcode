class Solution {
public:
    bool DFS(string s, string p,int i,int j,vector<vector<int>>&dp){
        if(dp[i][j]!=-1) return dp[i][j];
        if(i>=s.size() && j>=p.size()) return true;
        if(j>=p.size()) return false;
        bool match=(i<s.size() && (s[i]==p[j] || p[j]=='.'));
        if(j+1<p.size() && p[j+1]=='*'){
            dp[i][j]=DFS(s,p,i,j+2,dp) || (match && DFS(s,p,i+1,j,dp));
            return dp[i][j];
        }
        if(match){
           return dp[i][j]=DFS(s,p,i+1,j+1,dp);  
        }
        dp[i][j]=false;
        return false;
    }
    bool isMatch(string s, string p) {
       int n=s.size(),m=p.size(); 
       vector<vector<int>>dp(n+1,vector<int>(m+1,-1)); 
       return DFS(s,p,0,0,dp);
    }
};
