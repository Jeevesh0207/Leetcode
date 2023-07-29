class Solution {
public:
    double dp[200][200];
    double soupServings(int n) {
        memset(dp,-1,sizeof(dp));
        return (n>4800)?1.0:Solve((n+24)/25 , (n+24)/25);
    }
    double Solve(int a, int b){
        if(a<=0 && b<=0) return 0.5;
        if(a<=0) return 1;
        if(b<=0) return 0;
        if(dp[a][b]>0) return dp[a][b]; 
        return dp[a][b]=0.25*(Solve(a-4,b)+Solve(a-3,b-1)+Solve(a-2,b-2)+Solve(a-1,b-3));
    }
};
