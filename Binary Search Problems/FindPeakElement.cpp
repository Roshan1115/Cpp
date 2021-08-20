/*
find the peak element in a given array. Peak element is greater than its both left and right immediate neighbours.
*/

#include<iostream>
using namespace std;

int findPeakElement(int arr[], int n, int start, int end){
  if(start <= end){
    int mid = (start + end) / 2;

    if((mid == 0 || arr[mid] >= arr[mid-1]) && (mid == n-1 || arr[mid] >= arr[mid+1])){
      return arr[mid];
    }
    else if(mid > 0 && arr[mid] <= arr[mid-1]){
      return findPeakElement(arr, n, start, mid);
    }
    else{
      return findPeakElement(arr, n, mid, end);
    }
  }
  return -1;
}

int main(){
  int arr[] = {1,3,20,4,1,0,40,4};
  int n= 8;
  cout<< findPeakElement(arr, n, 0, n-1)<<endl;
  return 0;
}