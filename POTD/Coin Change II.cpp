class Solution {
public:
    vector<vector<int>>dp;
    int solve(int A,vector<int>&C ,int i){
        if(A<0 || i>=C.size()) return 0;
        if(A==0) return 1;
        if(dp[i][A]!=-1) return dp[i][A];
        int Take=solve(A-C[i],C,i);
        int notTake=solve(A,C,i+1);
        return dp[i][A]=Take+notTake;

    }
    int change(int A, vector<int>& C) {
        dp.resize(C.size()+1,vector<int>(A+1,-1));
        return solve(A,C,0);
    }
};
