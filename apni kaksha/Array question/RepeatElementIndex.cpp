#include<iostream>
#include<limits.h>  //for int_max or min
using namespace std;

void findRepeatingIndex(int a[], int size){
  const int s = 1e6+2;
  int idx[s]; // array of size !0^6
  for(int i=0; i<s; i++){
    idx[i] = -1;  // initialize all values with zero.
  }
  int minIndex = INT_MAX; 

  for(int i=0; i<size; i++){
    if(idx[a[i]] != -1)
      minIndex = min(minIndex, idx[a[i]]);
    else idx[a[i]] = i;
  }
  if(minIndex == INT_MAX) cout<<"No element repeating.\n";
  else cout<<minIndex<<endl;

}

int main(){
  
  int n;
    cout<<"Enter size of your array. ";
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++) cin>>arr[i];
    findRepeatingIndex(arr,n);
}