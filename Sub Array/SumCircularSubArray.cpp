#include<iostream>
#include<limits.h>
using namespace std;

int kadanes(int arr[], int n){
  int currSum = 0;
  int max_sum = INT_MIN;

  for(int i=0; i<n; i++){
    currSum += arr[i];
    if(currSum<0)  currSum = 0;
    max_sum = max(max_sum, currSum);
  }
  return max_sum;
}

int main(){
  int n ;
  cin>>n;
  int arr[n];
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }

  int nonwrapsum = kadanes(arr, n);

  int wrapsum, total=0;
  for(int i=0; i<n; i++){
    total += arr[i];
    arr[i] = -arr[i];
  }
  wrapsum = total + kadanes(arr, n);

  cout<<max(wrapsum, nonwrapsum)<<endl;

  return 0;
}