class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size()%2;
        int m=nums2.size()%2;
        int ans=0;
        for(auto i:nums1) if(m) ans^=i;
        for(auto i:nums2) if(n) ans^=i;
        return ans;
    }
};
