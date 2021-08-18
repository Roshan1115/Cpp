/*
given an array having lengths of board. given m number of painters. return the minimum time that the board can be painted if painters paint consecutively
*/

#include<iostream>
#include<limits.h>
using namespace std;

int findFeasible(int arr[], int n, int mid){
  int sum = 0, painters = 1;
  for(int i=0; i<n; i++){
    sum += arr[i];
    if(sum >mid){
      sum = arr[i];
      painters++;
    }
  }
  return painters;
}

int minimumPaintTime(int *arr, int n, int m){
  int totalLength = 0;
  int longestBoard = 0;

  for(int i=0; i<n; i++){
    longestBoard = max(longestBoard, arr[i]);
    totalLength += arr[i];
  }

  int low = longestBoard, high = totalLength;
  while(low < high){
    int mid = (low+high)/2;
    int painters = findFeasible(arr, n, mid);
    if(painters <= m){
      high = mid;
    }else{
      low = mid + 1;
    }
  }
  return low;
}

int main(){
  int arr[] = {10, 20, 30, 40};
  int n = 4, m = 2;
  cout<< minimumPaintTime(arr, n, m)<<endl;
   return 0;
}