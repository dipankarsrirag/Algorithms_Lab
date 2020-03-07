#include<iostream>
using namespace std;

int main() {
	int n, c;
	cout << "No.of items: ";
	cin >> n;
	cout << "Weight capacity of knapsack: ";
	cin >> c;
	int w[n], p[n], density[n];
	for(int i = 0; i < n; i++){
		cout << "Weight " << i << ": ";
		cin >> w[i];
		cout << "Profit " << i << ": ";
		cin >> p[i];
		density[i] = p[i]/w[i];
	}

	int profit = 0, loaded = 0;
	for(int i = 0; i < n-1; i++) {
		for(int j = 0; j < n-i-1; j++) {
			if(density[j] < density[j+1]) {
				swap(density[j], density[j+1]);
				swap(w[j],w[j+1]);
				swap(p[j],p[j+1]);
			}
		}
	}

	int i = 0;
	while(loaded < c && i < n) {
		if(loaded + w[i] > c)
		{
			i++;
			continue;
		}
		loaded += w[i];
		profit += p[i];
		i++;
	}

	cout << "Max profit obtained: " << profit << endl;

	return 0;
}
