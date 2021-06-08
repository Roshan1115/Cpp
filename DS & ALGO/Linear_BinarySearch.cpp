#include<iostream>
using namespace std;


void linearSearch(int arr[], int element, int size){
  for(int i = 0; i< size; i++){
    if(arr[i] == element) {
      cout<<"Element is at "<< i <<endl;
      return;
    }
  }
    cout<<"Element not found.\n";
}



void binarySearch(int arr[], int element, int lower, int upper){
  if(lower > upper){
    cout<<"Provide valid upper and lower bound.\n";
    return;
  }
  int mid = (lower + upper) / 2;

  if(arr[mid] == element){
    cout<<"Element is at "<< mid <<endl;
    return;
  }
  if(lower == mid && mid == upper){
    cout<<"Element is not present.\n";
    return;
  }
  if(arr[mid] > element){
    binarySearch(arr, element, lower, mid-1);
    return;
  }
  if(arr[mid] < element){
    binarySearch(arr, element, mid+1, upper);
    return;
  }
}


int main(){              
  int arr[] = {10,20,30,40,50,60,70,80,90,100};
  int size = 10, element;
  cout<<"Enter element to find ";
  cin>>element;
  int choice;
  bool value = true;


  // for user input to choose from both searching algorithms. ..................
  while(value){
    cout<<"Enter 1 for Linear Search and 2 for binary search.\n";
    cin>>choice;

    switch (choice)
    {
    case 1:
      linearSearch(arr, element, size);
      value = false;
      break;

    case 2:
      binarySearch(arr, element, 0, 9);
      value = false;
      break;
    
    default:
      cout<<"Enter valid option.\n";
      break;
    }
  }
  
  return 0;
}