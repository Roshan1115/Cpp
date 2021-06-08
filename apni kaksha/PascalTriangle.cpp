#include<iostream>
using namespace std;

int fact(int n){
  if(n == 0) return 1;

  int result = 1;
  for(int i = 2; i <= n; i++){
    result *= i;
  }
  return result;
}

int main(){
  int n;
  cout<<"Enter how many terms you want the pascal triangle to print to.\n";
  cin>>n;

  for(int i = 0; i< n; i++){
    for(int j = 0; j <= i; j++){
      // formula for nCr or here i C j;
      cout<< fact(i)/(fact(j)*fact(i-j)) <<" ";
    }
    cout<<endl;
  }
  return 0;
}