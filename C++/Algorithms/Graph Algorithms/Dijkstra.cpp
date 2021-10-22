//C++ implementation of Dijkstra algorithm
//Dijkstra is used to find shortest path from a given node
//to all the other nodes in a graph. This algorithm works only
//for positive edge weights
//Time Complexity: O((E+V)logV)
#include<bits/stdc++.h>
using namespace std;

#define inf 1e9

vector<int> dijkstra(vector<vector<pair<int,int>>> &adjacencyList, int n, int src){
	vector<bool> visited(n+1,false);
	//Initialize distances array with INFINITY
	vector<int> distances(n+1,1e9);
	//Declare a Min Heap
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push({0,src});
	distances[src] = 0;
	while(pq.size()){
		auto [t,node] = pq.top();
		pq.pop();
		if(visited[node])
			continue;
		visited[node] = true;
		//Traverse all nodes adjacent to the current node
		for(auto &[child,weight]: adjacencyList[node]){
			if(distances[child] > distances[node]+weight){
				distances[child] = distances[node]+weight;
				pq.push({distances[child],child});
			}
		}
	}
	distances.erase(distances.begin());
	return distances;
}

int main(){
	//Number of nodes
	int n;
	cin >> n;
	//Number of edges
	int m;
	cin >> m;
	//Store the graph as 2D vector of pairs.
	//where pair.first = adjacent node and pair.second = edge weight
	vector<vector<pair<int,int>>> adjacencyList(n+1);
	for(int i = 0; i < m; i++){
		//Node 1
		int u;
		cin >> u;
		//Node 2
		int v;
		cin >> v;
		//Edges weight
		int w;
		cin >> w;
		adjacencyList[u].push_back({v,w});
		adjacencyList[v].push_back({u,w});
	}
	int src;
	cin >> src;
	vector<int> distances = dijkstra(adjacencyList,n,src);
	for(int i: distances)
		cout << i << ' ';
	return 0;
}