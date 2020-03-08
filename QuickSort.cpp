#include <iostream>
using namespace std;

void swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

int Partition(int arr[], int l, int h){
  int piv = arr[h];
  int i = l-1;
  for(int j = l; j <= h-1; j++){
    if(arr[j] < piv){
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i+1], &arr[h]);
  return i+1;
}

void QuickSort(int arr[], int l, int h){
  if(l < h){
    int pi = Partition(arr,l,h);
    QuickSort(arr,l,pi-1);
    QuickSort(arr,pi+1,h);
  }
}

int main(){
  int arr[] = {5,2,1,8,10,62,12,54,7};
  int n = sizeof(arr)/sizeof(arr[0]);
  QuickSort(arr, 0, n-1);
  for(int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}
