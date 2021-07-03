// time complexity of count sort is O (max(array, n))f


#include<iostream>
using namespace std;

void countSort(int arr[], int n){
  int maxValue =0;
  for(int i=0; i<n; i++){
    maxValue = max(maxValue, arr[i]);
  }
  int temp[maxValue+1];
  for(int i=0; i<(maxValue+1); i++){
    temp[i] = 0;
  }

  for(int i=0; i<n; i++){
    temp[arr[i]]++;
  }

  for(int i=1; i<= maxValue; i++){
    temp[i] += temp[i-1];
  }

  int ansArray[n];
  for(int i=n-1; i>=0; i--){
    int pos = --temp[arr[i]];
    ansArray[pos] = arr[i];
  }

   cout<<"Sorted array : ";
   for(int i=0; i<n; i++){
    cout<< ansArray[i]<<" ";
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

  // int arr[] = {1,3,2,3,4,1,6,4,3};
  // int n = 9;
  countSort(arr, n);

  cout<<"Sorted array : ";
   for(int i=0; i<n; i++){
    cout<< arr[i]<<" ";
  }
  cout<<endl;

  return 0;
}