//https://www.codingninjas.com/studio/problems/bipartite-graph_1062589?leftPanelTab=0

#include <bits/stdc++.h> 
bool BFS(vector<vector<int>>&adj,int node,vector<int>&color){
	for(auto i:adj[node]){
		if(color[i]==-1){
			color[i]=!color[node];
			if(!BFS(adj,i,color)){
				return false;
			}
		}
		else if(color[i]==color[node]) return false;
	}
    return true;
}
bool isBipartite(vector<vector<int>>& graph, int vertices, int edges)
{
	int n=graph.size();
	vector<vector<int>>adj(vertices+1);
	for(int i=0;i<edges;i++){
		int u=graph[i][0];
		int v=graph[i][1];
		adj[u].push_back(v);
		adj[v].push_back(u); 
	}
    vector<int>color(vertices,-1);
	color[0]=0;
	return BFS(adj,0,color);
}
