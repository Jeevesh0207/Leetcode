class Solution {
public:
    static bool cmp(pair<int,int>& a, pair<int,int> &b)
    {
        return a.second < b.second;
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        vector<pair<int,int>>v;
        for(auto i:pairs){
            v.push_back({i[0],i[1]});
        }
        sort(v.begin(),v.end(),cmp);
        int ans=1;
        int p1=v[0].first,p2=v[0].second;
        for(int i=1;i<v.size();i++){
            if(p2<v[i].first){
                ans++;
                p2=v[i].second;
            }
        }
        return ans;
    }
};
