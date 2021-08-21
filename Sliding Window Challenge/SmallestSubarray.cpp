/*
for a fiven array and an integer x, find the smallest subarray size for which sum > x
*/

#include<iostream>
#include<limits.h>
using namespace std;

int minSumSubarray(int arr[], int n, int x){
  int ans = INT_MAX, sum = 0;
  int i=0, j=0;
  while(j<n){
    if(sum <= x){
      sum += arr[j];
      j++;
    }
    if(sum > x){
      ans = min(ans, j-i);
      sum -= arr[i];
      i++;
    }
  }
  return ans;
}

int main(){
  int arr[] = {1,4,45,6,10,19};
  int n=6, x = 51;
  cout<< minSumSubarray(arr, n, x)<<endl;
  return 0;
}