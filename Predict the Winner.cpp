class Solution {
public:
    int dp[23][23];
    int Solve(vector<int>&nums,int F,int L){
        if(F>L) return 0;
        if(F==L) return nums[F];
        if(dp[F][L]!=-1)return dp[F][L];
        int F_score=nums[F]-Solve(nums,F+1,L);
        int L_score=nums[L]-Solve(nums,F,L-1);
        return dp[F][L]=max(F_score,L_score);
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size()-1;
        memset(dp,-1,sizeof(dp));
        return Solve(nums,0,n)>=0;
    }
};


class Solution {
public:
    int dp[23][23];
    int Solve(vector<int>&nums,int F,int L){
        if(F>L) return 0;
        if(F==L) return nums[F];
        if(dp[F][L]!=-1)return dp[F][L];
        int F_score=nums[F]+min(Solve(nums,F+2,L),Solve(nums,F+1,L-1));
        int L_score=nums[L]+min(Solve(nums,F+1,L-1),Solve(nums,F,L-2));
        return dp[F][L]=max(F_score,L_score);
    }
    bool PredictTheWinner(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int n=nums.size();
        int T_sum=0;
        for(auto i:nums) T_sum+=i;
        int P1_score=Solve(nums,0,n-1);
        int P2_score=T_sum-P1_score;
        return P1_score>=P2_score;
    }
};
