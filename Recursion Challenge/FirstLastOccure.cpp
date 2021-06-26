// find the first and last occur of a given number in an array

#include<iostream>
using namespace std;

int firstOccur(int arr[], int n, int key){
  static int i = 0;

  if(i==n){
    return -1;
  }
  if(arr[i] == key){
    return i;
  }
  i++;
  return(firstOccur(arr, n, key));
}

int lastOccur(int arr[], int n, int key){
  static int i = 0;
  if(i == n){
    return -1;
  }
  i++;
  int store = lastOccur(arr, n, key);
  i--;
  if(arr[i] == key && store == -1){
    return i;
  }
  return store;
}

int main(){
  int array[] = {1,2,3,4,5,6,2,3};
  cout<< firstOccur(array, 8, 3);
  cout<< lastOccur(array, 8, 2);
  return 0;
}