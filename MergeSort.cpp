#include <iostream>
using namespace std;

void Merge(int arr[], int l, int m, int r){
  int i,j,k;
  int n1 = m - l + 1;
  int n2 =  r - m;
  int *L = new int[n1];
  int *R = new int[n2];

  for(i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for(i = 0; i < n2; i++)
    R[i] = arr[i + m + 1];
  /*
  i = l;
  j = 0;
  k = 0;
  while(j < n1 && k < n2){
    if(L[j] <= R[k])
      arr[i++] = L[j++];
    else
      arr[i++] = R[j++];
  }

  while(j < n1){
      arr[i++] = L[j++];
  }
  while(k < n2){
      arr[i++] = R[k++];
  }
  */
  i = 0;
  j = 0;
  k = l;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]){
      arr[k] = L[i];
      i++;
    }
    else{
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1){
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2){
    arr[k] = R[j];
    j++;
    k++;
  }
}

void MergeSort(int arr[], int l ,int r){
  if(l < r){
    int m = l+(r-l)/2;
    MergeSort(arr, l, m);
    MergeSort(arr, m+1, r);
    Merge(arr,l,m,r);
  }
}


int main(){
  int n;
  cout << "Enter the size of the array:" << endl;
  cin >> n;

  int *arr = new int[n];

  cout << "Enter elements in the array:" << endl;
  for(int i = 0; i < n; i++)
    cin >> arr[i];

  MergeSort(arr, 0, n-1);

  cout << "(Merge) Sorted array:" << endl;
  for(int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}
