#include<iostream>
#include<limits.h>
using namespace std;

int main(){
  int n;
  cout<<"Enter size of array. ";
  cin>>n;
  cout<<"Enter elements.\n";
  int arr[n];
  for (int i=0; i<n; i++){
    cin>>arr[i];
  }
  int position;
  cout<<"Enter the index of which you want maximum. ";
  cin>>position;
  
  int maxTill_i = INT_MIN;
  for(int i=0; i<=position; i++){
    maxTill_i = max(maxTill_i, arr[i]);
  }
  cout<<maxTill_i<<endl;
  return 0;
}