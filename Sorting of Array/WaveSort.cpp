// time complexity of wave sort is O(n/2) that is O(n)



#include<iostream>
using namespace std;

void WaveSort(int *arr, int n){
  for(int i=1; i<(n-1); i += 2){
    if(arr[i] > arr[i-1]){
      swap(arr[i], arr[i-1]);
    }
    if(arr[i] > arr[i+1]){
      swap(arr[i], arr[i+1]);
    }
  }

  for(int i=0; i<n; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

int main(){
  int n;
  cin>>n;
  int arr[n];


  for(int i=0; i<n; i++){
    cin>> arr[i];
  }

  WaveSort(arr, n);
  return 0;
}