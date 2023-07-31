//https://www.codingninjas.com/studio/problems/find-number-of-islands_630512?leftPanelTab=0

#include<bits/stdc++.h>
void BFS(int** arr,int n,int m,int row,int col,vector<vector<int>>&vis){
   vis[row][col]=1;
   queue<pair<int,int>>q;
   q.push({row,col});
   while(!q.empty()){
      int row=q.front().first;
      int col=q.front().second;
      q.pop();
      for(int delrow=-1;delrow<=1;delrow++){
         for(int delcol=-1;delcol<=1;delcol++){
           int nrow=row+delrow;
           int ncol=col+delcol;
           if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && arr[nrow][ncol]==1 && !vis[nrow][ncol]){
              vis[nrow][ncol]=1;
              q.push({nrow,ncol});
           } 
         }
      }
   }
}

int getTotalIslands(int** arr, int n, int m)
{
   vector<vector<int>>vis(n+1,vector<int>(m+1,0));
   int cnt=0;
   for(int row=0;row<n;row++){
      for(int col=0;col<m;col++){
         if(!vis[row][col] && arr[row][col]==1){
            cnt++;
            BFS(arr,n,m,row,col,vis);
         }
      }
   }
   return cnt;
}
