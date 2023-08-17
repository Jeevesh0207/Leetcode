class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
       queue<pair<int,int>>q; 
       for(int i=0;i<mat.size();i++){
           for(int j=0;j<mat[0].size();j++){
               if(mat[i][j]==0){
                   q.push({i,j});
               }
               else mat[i][j]=-1;
           }
       } 
       int x[]={-1,0,1,0};
       int y[]={0,1,0,-1};
       while(!q.empty()){
          int row=q.front().first;
          int col=q.front().second;
          q.pop();
          for(int i=0;i<4;i++){
              int nrow=row+x[i];
              int ncol=col+y[i];
              if(nrow<0 || nrow>=mat.size() || ncol<0 || ncol>=mat[0].size() || mat[nrow][ncol]!=-1) continue;
              q.push({nrow,ncol});
              mat[nrow][ncol]=mat[row][col]+1;
          } 
       }
       return mat;
    }
};
