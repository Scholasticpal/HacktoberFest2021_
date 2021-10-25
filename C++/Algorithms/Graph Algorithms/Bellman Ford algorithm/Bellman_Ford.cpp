#include <bits/stdc++.h> 
using namespace std;
map<int , char > mp;

struct Edge  // a structure to represent a weighted edge in graph 
{ 
	int src, dest, weight; 
}; 
struct Graph   // a structure to represent a connected, directed and weighted graph 
{ 
	
	int V, E;  // V-> Number of vertices, E-> Number of edges 
	struct Edge* edge; // graph is represented as an array of edges. 
	Graph(int V,int E)
	{
		this->V = V;
		this->E = E;
		edge = new Edge[E];
	}
};

void printArr(int dist[], int n)  // A function used to print the solution 
{ 
	cout<<"Vertex\t\tDistance from Source\n"; 
	for (int i = 0; i < n; ++i) 
	{
		cout<<mp[i]<<"\t\t\t"<<dist[i]<<endl;
	}
	cout<<endl;
} 
// The main function that finds shortest distances from src to all other vertices using 
//Bellman-Ford algorithm. The function also detects negative weight cycle 
void bellman(struct Graph* graph, int src) 
{ 
	int V = graph->V; 
	int E = graph->E; 
	int dist[V]; 
	// Step 1: Initialize distances from src to all other vertices as INFINITE 
	for (int i = 0; i < V; i++) 
		dist[i] = INT_MAX; 
	dist[src] = 0;
	// Step 2: Relax all edges |V| - 1 times. A simple shortest path from src to any other 
	//vertex can have at-most |V| - 1 edges 
	for (int i = 1; i <= V - 1; i++) 
	{ 
		for (int j = 0; j < E; j++) 
		{ 
			int u = graph->edge[j].src; 
			int v = graph->edge[j].dest; 
			int weight = graph->edge[j].weight; 
			if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) 
				dist[v] = dist[u] + weight; 
		} 
	} 
	// Step 3: check for negative-weight cycles. The above step guarantees shortest distances 
	//if graph doesn't contain negative weight cycle. 
	//If we get a shorter path, then there is a cycle. 
	for (int i = 0; i < E; i++) 
	{ 
		int u = graph->edge[i].src; 
		int v = graph->edge[i].dest; 
		int weight = graph->edge[i].weight; 
		if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) 
		{ 
			printf("Graph contains negative weight cycle"); 
			return;  // If negative cycle is detected, simply return 
		} 
	} 
	printArr(dist, V); 
	return; 
}

int main() 
{ 
	freopen("Input2.txt","r",stdin);
	freopen("Output2.txt","w",stdout);
	int V = 5;
	int E = 10;
	for(int i=0;i<V;i++)
	{
		char ch;
		cin>>ch;
		mp[i] = ch;
	}

	struct Graph* graph = new Graph(V, E); 
	for(int i=0;i<E;i++)
	{
		int x,y,wt;
		cin>>x>>y>>wt;
		graph->edge[i].src = x;
		graph->edge[i].dest = y; 
		graph->edge[i].weight = wt; 
	}
	cout<<"Implementation of Bellman - Ford Algorithm :\n\n";
		cout<<"When source is taken as vertex S:\n";
		bellman(graph, 0); 
	return 0; 
} 
