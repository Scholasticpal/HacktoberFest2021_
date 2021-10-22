// This algorithm is used to calculate the shortest distance between every
// pair of nodes of a graph
//Time Complexity: O(n^3)
// Space Complexity: O(n^2)

#include<bits/stdc++.h>
using namespace std;

#define inf 1e9
//edge strucure to store edges of graph
struct edge{
	int u,v,w;
	edge(int u, int v, int w): u(u), v(v), w(w) {}
};

void floyd_warshall(int n, int m, vector<edge> &edgeList){
	//Here, we assume only positive edge weights
	int distances[n+1][n+1];
	//Initialize the distances array with INTFINITY
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++){
			distances[i][j] = inf;
		}
	}
	for(int i = 0; i < m; i++){
		int u,v,w;
		u = edgeList[i].u;
		v = edgeList[i].v;
		w = edgeList[i].w;
		distances[u][v] = min(distances[u][v], w);
	}

	//Shortest distance of a node with itself is 0
	for(int i = 0; i <= n; i++)
		distances[i][i] = 0;

	//Distance between node i and node j with node k as an intermediate
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				distances[i][j] = min(distances[i][j], distances[i][k]+distances[k][j]);
			}
		}
	}
	//If node j is not reachable from node i, print -1
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(distances[i][j] >= inf)
				distances[i][j] = -1;
		}
	}
	//Print shortest distance between node i and node j
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cout << distances[i][j] << ' ';
		}
		cout << '\n';
	}
}
int main(){
	//Number of nodes
	int n;
	cin >> n;
	int m;
	//Number of edges
	cin >> m;
	
	//Store the graph as list of edges
	vector<edge> edgeList;
	for(int i = 0; i < m; i++){
		//Edge of weight w directed from u to v
		int u, v ,w;
		cin >> u >> v >> w;
		edgeList.push_back(edge(u,v,w));
		
	}
	floyd_warshall(n,m,edgeList);
	return 0;
}