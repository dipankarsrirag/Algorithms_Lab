#include<iostream>

using namespace std;

bool isBipartite(int** mat, int n, int visited[], int label[], int source) {
  // cout << v + 1 << endl;
  visited[source] = 1;
  for(int v = 1; v <= n; v++) {
    if(mat[source][v] == 1) {
      if(!visited[v]) {                       // if label of source is '0' then label of all it's
        label[v] = !label[source];            // adjacent vertices should be '1'
        if(!isBipartite(mat, n, visited, label, v)) return false;
      }                                       // recursively findout whether it fails
      else if(label[source] == label[v]) return false;
    }                                         // if two adjacent vertices have the same label
  }                                           // then the graph is not Bipartite
  return true;
}

void swap(int& a, int& b, int& c, int& d) {
  int t = a;                             // swap function
  a = b;
  b = t;

  t = c;
  c = d;
  d = t;
}

void selectionSort(int a[], int count[], int n) {
  int i, j, min_idx;                    // funtion to sort the set A according to number of
  for (i = 1; i <= n - 1; i++) {        // uncovered vertices in B (ascending order)
    min_idx = i;
    for (j = i + 1; j <= n; j++)
      if (count[j] < count[min_idx]) min_idx = j;
    swap(a[min_idx], a[i], count[min_idx], count[i]);
  }
}

int getMinCover(int** mat, int n, int a[], int x, int b[], int y, int minCover[]) {
  int count[x + 1];
  int covered[y];
  for(int i = 1; i <= x; i++) {
    count[i] = 0;
    for(int j = 1; j <= y; j++) {      // for an element in set A
      covered[j] = 0;                  // count the number of adjacent vertices in B
      if(mat[a[i]][b[j]] == 1) count[i]++; // (no of uncovered vertices)
    }
  }

  int size = 0;
  while(x >= 1) {                      // while there are elements in set A
    selectionSort(a, count, x);        // sort them according to no of uncovered vertices in B
    // cout << a[x] << "  " << count[x] <<  endl;
    if(count[x])                       // select the vertex with max no of uncovered vertices in B
      minCover[size++] = a[x];         // add that vertex to Minimum Cover
    for(int i = 1; i <= y; i++) {      // for an elememt in B
      if(mat[a[x]][b[i]] == 1 && !covered[i]) { // if that element is adjacent to this vertex
        covered[i] = 1;                // and if it was not covered
        for(int j = 1; j <= x; j++) if(mat[a[j]][b[i]] == 1) count[j]--;
      }                                // reduce the value of 'no of uncovered vertices' of
    }                                  // of all vertices connected to this vertex in B by 1
    // cout << x << " ";
    x--;
  }                                    // repeat
  return size;                         // return size of minCover
}

int** getMatrix(int v) {                          // dynamic matirix allocation
  int** mat = new int*[v];
  for(int i = 0; i < v; i++) {
    mat[i] = new int[v];
    for(int j = 0; j < v; j++) mat[i][j] = 0;    // initialize matrix to disconnected
  }
  return mat;
}

int main(int argc, char const *argv[]) {
  int n, e;
  cout << "Enter no of vertices : ";
  cin >> n;
  int** mat = getMatrix(n + 1);                 // generate matrix
  cout << "Enter no of edges : ";
  cin >> e;
  int from, to;
  for(int i = 0; i < e; i++) {
    cout << "Enter edge : ";
    cin >> from >> to;
    mat[from][to] = 1;                          // undirected graph
    mat[to][from] = 1;
  }

  int label[n + 1], visited[n + 1];             // label for Bipartite (0 - set A, 1 - set B)
  int source = 1;

  for(int i = 1; i <= n; i++) {
    label[i] = -1;
    visited[i] = 0;                             // visited = false
  }

  label[source] = 0;                            // add source vertex to set A
  int ans = isBipartite(mat, n, visited, label, source);  // find out whether Bipartite or not
  if(!ans) cout << "Not Bipartite" << endl;
  else {                                      // if Bipartite
    // for(int i = 1; i <= n; i++) cout << label[i] << endl;
    int x = 0, y = 0;
    for(int i = 1; i <= n; i++) {
      if(!label[i]) x++;                      // count elements of set A and B
      else y++;
    }
    int a[x], b[y];
    x = y = 1;

    for(int i = 1; i <= n; i++) {
      if(!label[i]) a[x++] = i;              // create the Bipartite by adding elements into
      else b[y++] = i;                       // set A and B based on labels
    }

    x--; y--;
    int minCover[x + 1];                     // find the Minimum Cover
    int size = getMinCover(mat, n, a, x, b, y, minCover);
    cout << "Minimum Bipartite Cover : ";
    for(int i = 0; i < size; i++) cout << minCover[i] << " ";
  }
  return 0;
}
