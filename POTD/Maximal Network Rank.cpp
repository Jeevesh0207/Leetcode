class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int>arr(n,0);
        vector<vector<int>>dirCon(n,vector<int>(n,0));
        for(auto i:roads){
            arr[i[0]]++;
            arr[i[1]]++;
            dirCon[i[0]][i[1]]=1;
            dirCon[i[1]][i[0]]=1;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans=max(ans,arr[i]+arr[j]-dirCon[i][j]);
            }
        }
        return ans;
    }
};
