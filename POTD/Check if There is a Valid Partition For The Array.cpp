class Solution {
public:
    vector<int>dp;
    bool Solve(vector<int>&N,int i){
        if(i>N.size()) return false;
        if(i==N.size()) return true;
        if(dp[i]!=-1) return dp[i];
        bool flag=false;
        if(i+1<N.size() && N[i]==N[i+1]) flag=flag||Solve(N,i+2);
        if(i+2<N.size() && N[i]==N[i+1] && N[i+1]==N[i+2]) flag=flag||Solve(N,i+3);
        if(i+2<N.size() && N[i+1]-N[i]==1 && N[i+2]-N[i+1]==1) flag=flag||Solve(N,i+3);
        return dp[i]=flag;
    }
    bool validPartition(vector<int>& nums) {
        dp.resize(nums.size()+1,-1);
        return Solve(nums,0);
    }
};
