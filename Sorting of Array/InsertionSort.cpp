#include<iostream>
using namespace std;

int main(){
  int n;
  cout<<"Enter size of the array. ";
  cin>>n;
  int arr[n];
  cout<<"Enter elements.\n";
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }

  for(int i=1; i<n; i++){
    int position = i;
    while(arr[position] < arr[position-1] && position > 0){
      int temp = arr[position];
      arr[position] = arr[position-1];
      arr[position-1] = temp;

      position--;
    }
  }

  cout<<"Sorted array is ";
  for(int i=0; i<n; i++){
    cout<<arr[i]<<" ";
  }
  return 0;
}