class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto i:nums) mp[i]++;
        vector<vector<int>>ans;
        int mx=0;
        for(auto &i:mp){
           mx=max(mx,i.second);
        }
        while(mx--){
            vector<int>T;
            for(auto &i:mp){
                if(i.second!=0)
                {
                    T.push_back(i.first);
                    i.second--;
                }
            }
            ans.push_back(T);
        }
        return ans;
    }
};
