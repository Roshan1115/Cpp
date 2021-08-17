/*
Given a sorted array having pages on books. return the minimum of maximum pages a student get. given m student
*/

#include<iostream>
#include<limits.h>
using namespace std;

bool isPossible(int arr[], int n, int m, int mid){
  int students = 1, sum = 0;
  for(int i=0; i<n; i++){
    if(arr[i] > mid){
      return false;
    }
    if(sum + arr[i] > mid){
      students++;
      sum = arr[i];
      if(students > m){
        return false;
      }
    }
    else{
      sum += arr[i];
    }
  }
  return true;
}

int minpageAlocate(int arr[], int n, int m){
  int sum = 0;
  if(n < m) return -1;

  for(int i=0; i<n; i++){
    sum += arr[i];
  }
  int start = 0, end = sum, ans = INT_MAX;
  while(start <= end){
    int mid = (start + end)/2;

    if(isPossible(arr, n, m, mid)){
      ans = min(ans, mid);
      end  = mid - 1;
    } else{
      start = mid +1;
    }
  }
  return ans;
}

int main(){
  int arr[] = {12, 34, 67, 90};
  int n = 4, m = 2;

  cout<<"The minimum number of page : "<< minpageAlocate(arr, n, m)<<endl;
  return 0;
}