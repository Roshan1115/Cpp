#include<iostream>
using namespace std;

int main(){
  int n;
  cout<<"Enter size. ";
  cin>>n;
  int arr[n];
  cout<<"Enter "<<n<<" elements.\n";
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }

  int l=0, r=1, last=n-1;

  while(last > 1){

    while(r <= last){
      if(arr[r] < arr[l]){
        int temp = arr[l];
        arr[l] = arr[r];
        arr[r] = temp;
      }
      l++; r++;
    }

    last--;
    l=0; r=1;
  }

  cout<<"Sorted array is\n";
  for(int i=0; i<n; i++){
    cout<<arr[i]<<" ";
  }
  return 0;
}