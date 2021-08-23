/*
for a given array and integer k, find the maximum perfect numbers of size k.
perfect no is a no which is equal to the sum of its proper positive divisor. eg 6 which is sum of 1,2 and 3.
*/

#include<iostream>
#include<cmath>
using namespace std;

bool isPerfect(int n){
  int sum = 1;
  for(int i=2; i< sqrt(n); i++){
    if(n % i == 0){
      if(i == n/i){
        sum += i;
      }else{
        sum += i + n/i;
      }
    }
  }
  return sum == n;
}

int maxPerfecctNo(int arr[], int n, int k){
  int binaryArr[n];
  for(int i=0; i<n; i++){
    if(isPerfect(arr[i])){
      binaryArr[i] = 1;
    }else{
      binaryArr[i] = 0;
    }
  }

  int sum = 0, ans = 0;
  for(int i=0; i<k; i++){
    sum += binaryArr[i];
  }
  ans = max(ans, sum);

  for(int i=k; i<n; i++)
  {
    sum = sum - binaryArr[i-k] + binaryArr[i];
    ans = max(ans, sum);
  }
  return ans;
}

int main(){
  // cout<< isPerfect(6)<<endl;
  int arr[] = {28, 2, 3, 6, 496, 99, 8128, 24};
  int k = 4, n = 8;
  cout<< maxPerfecctNo(arr, n, k)<< endl;
  return 0;
}