/*
Given an arry of n size, and integer k. find the maximum of the minimum difference of any pair in the group of k elements.
*/

#include<iostream>
#include<algorithm>
using namespace std;

bool isFeasible(int mid, int arr[], int n, int k){
  int pos = arr[0], elements = 1;
  for(int i=1; i<n; i++){
    if(arr[i] - pos >= mid){
      pos = arr[i];
      elements++;
      if(elements == k){
        return true;
      }
    }
  }
  return false;
}

int Maxofmindist(int arr[], int n, int k){
  sort(arr, arr+n);

  int left = 1, right = arr[n-1], result = -1;
  while(left<right){
    int mid = (left + right)/2;

    if(isFeasible(mid, arr, n, k)){
      result = max(result, mid);
      left = mid +1;
    }else{
      right = mid;
    }
  }

  return result;
}

int main(){
  int n = 5, k = 3;
  int arr[] = {3,2,6,15,9};
  cout<<"Largest min diistance is : "<< Maxofmindist(arr, n, k)<<endl;
  return 0;
}