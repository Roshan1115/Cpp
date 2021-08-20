/*
given an array and two integer k and x. find the sum of a subarray of size k having sum less than x.
*/

#include<iostream>
using namespace std;

int maxSumSubarray(int arr[], int n, int k, int x){
  int ans = 0, sum = 0;

  for(int i=0; i<k; i++){
    sum += arr[i];
  }
  if(sum < x){
    ans = sum;
  }

  for(int i=k; i<n; i++){
    sum = sum - arr[i-k] + arr[i];
    if(sum < x){
      ans = max(ans, sum);
    }
  }
  return ans;
}

int main(){
  int arr[] = {7,5,4,6,8,9};
  int n = 6, k = 3, x = 20;
  cout<< maxSumSubarray(arr, n, k, x)<< endl;
  return 0;
}