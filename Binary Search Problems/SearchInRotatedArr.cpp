/*
given a sorted array which is rotate in one point. seaerch element in time < O(n).
*/


#include<iostream>
using namespace std;

int searchInRotatedarr(int arr[], int key, int left, int right){
  if(left > right) return -1;

  int mid = (left + right)/2;
  if(arr[mid] == key) return mid;

  if(arr[left] <= arr[mid]){
    if(key >= arr[left] && key <= arr[mid]){
      return searchInRotatedarr(arr, key, left, mid-1);
    }
    return searchInRotatedarr(arr, key, mid+1, right);
  }

  if(key >= arr[mid] && key <= arr[right]){
    return searchInRotatedarr(arr, key, mid+1, right);
  }
  return searchInRotatedarr(arr, key, left, mid-1);
}

int main(){
  int arr[] = {6,7,8,1,2,3,4,5};
  int n = 8;
  int key = 3;
  cout<< searchInRotatedarr(arr, key, 0, n-1)<<endl;
  return 0;
}