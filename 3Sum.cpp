class Solution {
public:
    vector<vector<int>>ans;
    void Solve(vector<int>&nums, int x,int i){
        int n=nums.size();
        int L=i;
        int R=n-1;
        while(L<R){
            int T=nums[x] + nums[L] + nums[R];
            if(T==0){
                int Left=nums[L];
                int Right=nums[R];
                ans.push_back({nums[x],nums[L],nums[R]});
                while(L<R && Left==nums[L])L++;
                while(L<R && Right==nums[R])R--;
            }
            else if(T>0) R--;
            else L++;
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
               if(i==0 || nums[i-1]!=nums[i]){
                   Solve(nums,i,i+1);
               }
        }
        return ans;
    }
};
