class Solution {
public:
    int dp[1001][1001]={0};
    
    int Solve(string &s1, string &s2,int n,int m){
      for(int i=1;i<=n;i++){
          dp[i][0]=dp[i-1][0]+s1[i-1];
          for(int j=1;j<=m;j++){
              dp[0][j]=dp[0][j-1]+s2[j-1];
              if(s1[i-1]==s2[j-1]){
                  dp[i][j]=dp[i-1][j-1];
              }
              else {
                  dp[i][j]=min(s1[i-1]+dp[i-1][j],s2[j-1]+dp[i][j-1]);
              }
              for(int i=0;i<=n;i++){
                for(int j=0;j<=m;j++){
                    cout<<dp[i][j]<<' ';
              }
          cout<<endl;
      }
          }
      }
      
      return dp[n][m];
    }
    int minimumDeleteSum(string &s1, string &s2) {
       int n=s1.size(),m=s2.size();
       return Solve(s1,s2,n,m); 
    }
};
