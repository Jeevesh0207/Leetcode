class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        vector<int>v;
        int i=0,j=0;
        while(i<n && j<m){
            if(nums1[i]<nums2[j])v.emplace_back(nums1[i++]);
            else v.emplace_back(nums2[j++]);
        }
        while(i<n) v.emplace_back(nums1[i++]);
        while(j<m) v.emplace_back(nums2[j++]);
        int sz=v.size();
        if(v.size()&1){
            return v[sz/2];
        }
        return (double)(v[sz/2]+v[(sz/2)-1])/2;
    }
};
