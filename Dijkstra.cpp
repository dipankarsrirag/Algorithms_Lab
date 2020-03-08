#include <iostream>
using namespace std;

class Graph{
public:
	int V;
  int **adj, *dist, *par;
  bool *sptSet;

  Graph(int V){
	   this->V = V;

     adj = new int* [V];
     dist = new int[V];
     par = new int[V];
     sptSet = new bool[V];

     for (int i = 0; i < V; i++){
        adj[i] = new int[V];
        dist[i] = INT_MAX;
        sptSet[i] = false;
      }

     for (int i = 0; i < V; i++)
      for (int j = 0; j < V; j++)
        adj[i][j] = 0;
  }

	void addEdge(int u, int v, int cost) {
		adj[u][v] = cost;
	}

  int minDistance(){

    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
  }

  void print() {

    cout << "Vertex \t\t Distance from Source \t Parent" << endl;
    for (int i = 0; i < V; i++)
      cout << i << "\t\t\t" << dist[i] << "\t\t" << par[i] << endl;
  }

  void Dijkstra(int src) {

    dist[src] = 0;
    for (int count = 0; count < V - 1; count++){

        int u = minDistance();

        sptSet[u] = true;

        for (int v = 0; v < V; v++)
          if (!sptSet[v] && adj[u][v] && dist[u] != INT_MAX
                && dist[u] + adj[u][v] < dist[v]){
                dist[v] = dist[u] + adj[u][v];
                par[v] = u;
              }
      }
    print();
  }
};

int main(){

  cout << "Enter no. of vertices:" << endl;
  int v,src,dest,cost;
  cin >> v;

	Graph g(v);

  while(src != -1){
    cout << "Enter source vertex:" << endl;
    cin >> src;
    if(src == -1)
      break;
    cout << "Enter dest. vertex:" << endl;
    cin >> dest;
    cout << "Enter cost:" << endl;
    cin >> cost;
    g.addEdge(src,dest,cost);
  }
  cout << "Source vertex:" << endl;
  cin >> src;

  g.Dijkstra(src);

	return 0;
}
