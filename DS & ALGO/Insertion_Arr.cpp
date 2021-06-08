#include<iostream>
using namespace std;

int size;

int insert(int arr[], int element, int capacity, int index){
  if(size >= capacity) return -1;

  // Code for insertion
  for(int i = size -1; i >= index; i--){
    arr[i+1] = arr[i];
  }
  arr[index] = element;
  size = size + 1;
  return 1;
}

int main(){
  int arr[100] = {4,6,33,54,56,67};
  int element, index;
  cout<<"What is the current size of your array ?\n";
  cin>>size;
  cout<<"Enter element to be inserted\n";
  cin>>element;
  cout<<"Enter the index where you want to insert the element\n";
  cin>>index;

  cout<<"Arry before inserting is ";
  for(int i = 0; i< size; i++){
    cout<<arr[i]<<" ";
  }
  insert(arr, element, 100, index);

  cout<<"Arry after inserting is ";
  for(int i = 0; i< size; i++){
    cout<<arr[i]<<" ";
  }

  return 0;
}