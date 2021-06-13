#include<iostream>
using namespace std;

int main(){
  int n;
  cin>>n;
  char arr[n+1];
  cin>> arr;

  bool check = true;
  
  for(int i=0; i<= n/2; i++){
    if(arr[i] != arr[n-1-i]) {
      check = false;
      break;
    }
  }
  
  if(check) cout<<"The word is palindrom";
  else cout<<"The word is not palindrom.";
  return 0;
}