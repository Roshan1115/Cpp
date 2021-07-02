// time complexity of merge sort is  = n log(n)


#include<iostream>
using namespace std;

void merge(int arr[], int l, int mid, int r){
  int size1 = mid-l+1;
  int size2 = r-mid;

  int a[size1], b[size2];

  // assigning the value into a and b temporary array.
  for(int i=0; i< size1; i++){
    a[i] = arr[l+i];
  }
  for(int i=0; i< size2; i++){
    b[i] = arr[mid+1+i];
  }

  int i=0, j=0, k=l;
  while(i<size1 && j<size2){
    if(a[i] < b[j]){
      arr[k] = a[i];
      i++; k++;
    }
    else{
      arr[k] = b[j];
      j++; k++;
    }
  }

  while(i<size1){
     arr[k] = a[i];
      i++; k++;
  }
  while(j<size2){
     arr[k] = b[j];
      j++; k++;
  }
}

void mergSort(int arr[], int l,int r){
  if(l < r){
    int mid = (l+r) / 2;
    mergSort(arr, l, mid);
    mergSort(arr, mid+1, r);

    merge(arr, l, mid, r);
  }
}

int main(){
  int n;
  cin>>n;
  int arr[n];
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }
  mergSort(arr, 0, n-1);

  cout<<"Sorted array : ";
   for(int i=0; i<n; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  return 0;
}