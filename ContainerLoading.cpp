#include <list>
#include <iostream>
using namespace std;

void display(list <int> l){
    list <int> :: iterator i;
    for(i = l.begin(); i != l.end(); ++i)
        cout << *i << '\t';
    cout << '\n';
}

void ContainerLoading(list <int> l, int cap, int n){
  list <int> ship;
  l.sort();

  list <int> :: iterator i;

  for(i = l.begin(); i != l.end() && *i <= cap; i++){
    ship.push_back(*i);
    cap -= *i;
  }

  display(ship);
}

int main(int argc, char const *argv[]) {
  int cap, n;

  cout << "Enter capacity of the ship:" << endl;
  cin >> cap;

  cout << "Enter no. of containers:" << endl;
  cin >> n;

  list <int> l;

  int j;

  cout << "Enter weights of the containers:" << endl;
  for(int i = 0; i < n; i++){
    cin >> j;
    l.push_back(j);
  }

  cout << "Containers on the ship are:" << endl;
  ContainerLoading(l, cap, n);
  return 0;
}
