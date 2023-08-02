class Solution {
public:
    vector<vector<int>>ans;
    void Solve(vector<int>&nums,int index){
       if(index==nums.size()){
           ans.push_back(nums);
           return;
       }
       for(int i=index;i<nums.size();i++){
           swap(nums[index],nums[i]);
           Solve(nums,index+1);
           swap(nums[index],nums[i]);
       }
    }
    vector<vector<int>> permute(vector<int>& nums) {
       Solve(nums,0);
       return ans;
    }
};
