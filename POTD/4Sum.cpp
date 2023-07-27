#define ll long long int
class Solution {
public:
    set<vector<int>>ans;
    void Solve(vector<int>&nums,ll F , int i ,int n1,int n2){
        int L=i;
        int R=nums.size()-1;
        while(L<R){
            ll sum=nums[L]+nums[R];
            if(sum==F){
                int Left=nums[L];
                int Right=nums[R];
                ans.insert({n1,n2,nums[L],nums[R]});
                while(L<R && Left==nums[L])L++;
                while(L<R && Right==nums[R])R--;
            }
            else if(sum>F) R--;
            else L++;
        }
    }
    vector<vector<int>> fourSum(vector<int>& nums, int T) {
        sort(nums.begin(),nums.end());
        ll n=nums.size();
        for(int i=0;i<n-3;i++){
            ll n1=nums[i];
            for(int j=i+1;j<n-2;j++){
                ll n2=nums[j];
                ll F= T -(n1+n2);
                Solve(nums,F,j+1,n1,n2);
            }
        }
        vector<vector<int>>res;
        for(auto i:ans){
            res.push_back(i);
        }
        return res;
    }
};
