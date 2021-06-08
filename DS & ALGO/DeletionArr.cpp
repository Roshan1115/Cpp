#include<iostream>
using namespace std;

int size;

void display(int arr[], int size){
  for(int i = 0; i<size; i++) cout<<arr[i]<<" ";

}

void deletion(int arr[], int index){
  for(int i = index; i < size -1; i++) arr[i] = arr[i+1];
  size -= 1;
}

int main(){
  int arr[100] = {4,6,33,54,56,67};
  int element, index;
  cout<<"What is the current size of your array ?\n";
  cin>>size;
  cout<<"Enter the index of element that you want to delete\n";
  cin>>index;
  cout<<"Before deletion : ";
  display(arr, size);
  cout<<endl;
  
  deletion(arr, index);

  cout<<"After deletion : ";
  display(arr, size);
  cout<<endl;

  

  return 0;
}