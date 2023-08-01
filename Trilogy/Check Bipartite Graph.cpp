//https://www.codingninjas.com/studio/problems/check-graph-is-bipartite-or-not_920551?leftPanelTab=1

bool BFS(vector<int>&color,int node,vector<vector<int>>&graph){
	for(auto i:graph[node]){
		if(color[i]==-1){
			color[i]=!color[node];
			if(!BFS(color,i,graph)){
				return false;
			}
		}
		else if(color[i]==color[node]) return false;
	}
	return true;
}

bool isGraphBirpatite(vector<vector<int>> &edges) {
	int n=edges.size();
	vector<vector<int>>graph(n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(edges[i][j]){
				graph[i].push_back(j);
				graph[j].push_back(i);
			}
		}
	}
	vector<int>color(n,-1);
	color[0]=0;
	return BFS(color,0,graph);
}
