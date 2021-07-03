// DNF = Dutch National Flag sort
// given an array containing only 1s, 2s and 3s .

// time complexity of DNF sort is O(n).

#include<iostream>
using namespace std;

void DNF_Sort(int a[], int n){
  int low = 0;
  int mid = 0;
  int high = n-1;

  while(mid < high){
    if(a[mid] == 0){
      swap(a[low], a[mid]);
      low++;
      mid++;
    }
    else if(a[mid] == 1)  mid++;
    else if(a[mid] == 2){
      swap(a[mid], a[high]);
      high--;
    }
  }
}

int main(){
  int arr[] = {1, 0, 2, 1, 0, 1, 2, 1, 2};

  DNF_Sort(arr, 9);

  for(int i=0; i< 9; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  return 0;
}