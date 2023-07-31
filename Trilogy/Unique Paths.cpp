class Solution {
public:
    long long uniquePaths(int m, int n) {
       int N=n+m-2;
       int R=m-1;
       double ans=1;
       for(int i=1;i<=R;i++){
           ans= ans*(N-R+i)/i;
       }
       return (int)ans;
    }
};

class Solution {
public:
    int dp[101][101];
    int Solve(int i,int j,int m,int n){
        if(i==n-1 && j==m-1) return 1;
        if(i>=n || j>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=Solve(i+1,j,m,n) + Solve(i,j+1,m,n);
    }
    long long uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        return Solve(0,0,m,n);
    }
};
