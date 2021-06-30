#include<iostream>
using namespace std;

int main(){
  int n;
  cout<<"Enter size of array. ";
  cin>>n;
  int arr[n];
  cout<<"Enter elements.\n";

  for(int i=0; i<n; i++){
    cin>>arr[i];
  }
  const int N = 1e6 + 2;
  bool check[N];

  for(int i=0; i<N; i++){
    check[i] = false;
  }
  int ans = -1;

  for(int i=0; i<n; i++){
    if(arr[i] >=0)  check[arr[i]] = true;
  }
  for(int i=0; i<N; i++){
    if(check[i] == false){
      ans = i;
      break;
    }
  }
  cout<<ans<<endl;
  return 0;
}