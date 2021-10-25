//DFS Algorithm to check if given graph is bipartite or not.

#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>> &adjacencyList, vector<int> &colors, int node, int prev){
	if(colors[node] != -1){
		if(colors[node] == colors[prev])
			return true;
		else
			return false;
	}
	colors[node] = (1+colors[prev])%2;
	for(int child: adjacencyList[node]){
		if(dfs(adjacencyList,colors,child,node))
			return true;
	}
	return false;
}

bool bipartite(vector<vector<int>> &adjacencyList, int n){
	vector<int> colors(n+1,-1);
	colors[0] = 0;
	return !dfs(adjacencyList,colors,1, 0);
}

int main(){
	//Number of nodes
	int n;
	cin >> n;
	//Number of edges
	int m;
	cin >> m;
	vector<vector<int>> adjacencyList(n+1);
	for(int i = 0; i < m; i++){
		int u,v;
		cin >> u >> v;
		adjacencyList[u].push_back(v);
		adjacencyList[v].push_back(u);
	}
	if(bipartite(adjacencyList,n))
		cout << "Graph is Bipartite";
	else
		cout << "Graph is non Bipartite";
	return 0;
}