// find the unique number in an array which occur only once.

#include<iostream>
using namespace std;

int unique(int arr[], int size){
  int XOR_Sum = 0;
  for(int i=0; i<size; i++){
    XOR_Sum = XOR_Sum^arr[i];
  }
  return XOR_Sum;
}

int main(){
  int arr[] = {1, 4, 2, 3, 1, 3, 2};
  cout<< unique(arr, 7);
  return 0;
}