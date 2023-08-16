class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        deque<int>Dq;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(!Dq.empty() && Dq.front()==i-k) Dq.pop_front();
            while(!Dq.empty() && nums[Dq.back()]<nums[i]) Dq.pop_back();
            Dq.push_back(i);
            if(i>=k-1) ans.push_back(nums[Dq.front()]);
        }
        return ans;
    }
};
