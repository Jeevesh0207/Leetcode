class Solution {
public:
    vector<vector<int>>dp;
    int Solve(vector<vector<int>>G,int i,int j){
        if(i>=G.size() || j>=G[0].size() || G[i][j]==1) return 0;
        if(i==G.size()-1 && j==G[0].size()-1){
            return 1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int Right = Solve(G,i,j+1);
        int Down = Solve(G,i+1,j);
        return dp[i][j]=Right+Down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& Grid) {
        dp.resize(Grid.size()+1,vector<int>(Grid[0].size()+1,-1));
        return Solve(Grid,0,0);
    }
};
