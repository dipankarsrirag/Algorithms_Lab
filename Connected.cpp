#include <iostream>
#include <list>
#include <stack>
using namespace std;

class Graph {
	int V;
	list<int> *adj;

	void DFSUtil(int v, bool visited[]);
public:
	Graph(int V) { this->V = V; adj = new list<int>[V];}

	void addEdge(int v, int w);

	bool isConnected();
};

void Graph::DFSUtil(int v, bool visited[]) {
	visited[v] = true;

	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFSUtil(*i, visited);
}

void Graph::addEdge(int v, int w) {
	adj[v].push_back(w);
}

bool Graph::isConnected() {
	bool visited[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	DFSUtil(0, visited);

	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			return false;

	return true;
}

int main() {
	Graph g1(5);
	g1.addEdge(0, 1);
	g1.addEdge(0, 2);
	g1.addEdge(1, 3);
	g1.addEdge(2, 3);
	g1.addEdge(4, 4);
	g1.isConnected()? cout << "Yes\n" : cout << "No\n";



	return 0;
}
