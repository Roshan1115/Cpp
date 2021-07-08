/* count the number of inversion of a given array.
two element form an inversion if a[i] > a[j] where i < j.

to do it in more optimized way we use mergesort techique
*/

#include<iostream>
using namespace std;

long long merg(int *arr, int l, int mid, int r){
  long long count = 0;
  int n1 =  mid -l + 1;
  int n2 = r - mid;
  int a[n1], b[n2];

  for(int i=0; i<n1; i++){
    a[i] = arr[i+l];
  }
  for(int i=0; i<n2; i++){
    b[i] = arr[mid+1+i];
  }

  int i=0, j=0, k=l;

  while(i<n1 && j<n2){
    if(a[i] < b[j]){
      arr[k] = a[i];
      i++; k++;
    }
    else{
      arr[k] = b[j];
      count += n1 - i;  // this satisfy the inversion of array a.
      j++; k++;
    }
  }

  while(i<n1){
    arr[k] = a[i];
      i++; k++;
  }
  while(j<n2){
    arr[k] = b[j];
      count += n1 - i;
      j++; k++;
  }
  
  return count;
}

long long mergSort(int *arr, int l, int r){
  long long count = 0;
  
  if(l<r){
    int mid = (l+r) / 2;
    count += mergSort(arr, l, mid);
    count += mergSort(arr, mid+1, l);

    count += merg(arr, l, mid, r);
  }


  return count;
}

int main(){
  int n;
  cin>>n;
  int arr[n];

  for(int i=0; i<n; i++){
    cin>> arr[i];
  }

  cout<< mergSort(arr, 0, n-1);

  return 0;
}