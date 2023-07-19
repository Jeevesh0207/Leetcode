class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& I) {
       int ans=-1;
       sort(I.begin(),I.end(),[&](auto const& a,auto const& b){
           return a[1]<b[1];
       });
       int prev=I[0][1];
       for(int i=0;i<I.size();i++){
           if(I[i][0]<prev) ans++;
           else prev=I[i][1];
       }
       return ans;
    }
};
