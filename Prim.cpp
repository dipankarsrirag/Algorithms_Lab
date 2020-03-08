#include <iostream>
using namespace std;

class Graph{
public:
	int V;
  int **adj, *par, *key;
  bool *mstSet;
  queue <int> q;

  Graph(int V){
	   this->V = V;

     adj = new int* [V];
     par = new int[V];
     key = new int[V];
     mstSet = new bool[V];


     for (int i = 0; i < V; i++){
        adj[i] = new int[V];
        key[i] = INT_MAX,
        mstSet[i] = false;
      }

     for (int i = 0; i < V; i++)
      for (int j = 0; j < V; j++)
        adj[i][j] = 0;
  }

	void addEdge(int u, int v, int cost) {
		adj[u][v] = cost;
    adj[v][u] = cost;
	}

  int minKey() {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
  }

  void print() {
    cout<<"Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << par[i] <<" - "<<i<<" \t"<< adj[i][par[i]] <<" \n";
  }

  void Prim() {
    key[0] = 0;
    par[0] = -1;
    for (int count = 0; count < V - 1; count++) {

        int u = minKey();

        mstSet[u] = true;

        for (int v = 0; v < V; v++)
          if (adj[u][v] && mstSet[v] == false && adj[u][v] < key[v])
                par[v] = u, key[v] = adj[u][v];
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


  g.Prim();

	return 0;
}
