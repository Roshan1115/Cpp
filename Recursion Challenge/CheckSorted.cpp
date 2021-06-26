// check if an array is sorted or not 

#include<iostream>
using namespace std;

bool checkSorted(int arr[], int n){
  if(n==1){
    return true;
  }

  bool restArr = checkSorted(arr+1, n-1);
  return (arr[0]<= arr[1] && restArr);
}

int main(){
  int array[] = {1,2,3,4,5,6};
  cout<< checkSorted(array, 6);
  return 0;
}