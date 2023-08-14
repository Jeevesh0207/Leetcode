class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>p;
        for(auto i:nums){
            p.push(i);
        }
        k--;
        while(k--) p.pop();
        return p.top();
    }
};
