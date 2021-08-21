/*
for a given array and integer k, check if any sybarray of size k form a number divisible by 3 or not
*/

#include<iostream>
using namespace std;

// helper function
int digitSum(int n){
  int ans = 0;
  while(n > 0){
    int mod = n % 10;
    ans += mod;
    n = n/10;
  }
  return ans;
}

bool divisibleby3(int arr[], int n, int k){
  int sum = 0;
  for(int i=0; i<k; i++){
    sum += digitSum(arr[i]);
  }
  if(sum % 3 == 0){
    return true;
  }
  for(int i=k; i<n; i++){
    sum = sum - digitSum(arr[i-k]) + digitSum(arr[i]);
    if(sum % 3 == 0){
      // for printing the values
      for(int j= i-k+1; j<= i; j++){
        cout<<arr[j]<<" ";
      }cout<<endl;
      return true;
    }
  }
  return false;
}

int main(){
  int arr[] = {8, 23, 45, 12, 56, 4};
  int n = 6, k = 3;

  cout<< divisibleby3(arr, n, k)<< endl;

  return 0;
}