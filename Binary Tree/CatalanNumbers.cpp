/*
this problem is so much time consuming and we will reduce teh time complexity using dynamic programing later. 
*/


#include<iostream>
using namespace std;

int catalan(int n){
  if(n <= 1) return 1;
  int res = 0;
  for(int i=0; i<n; i++){
    res += catalan(i) * catalan(n-1-i);
  }
  return res;
}

int main(){
  // print catalan number from 1 to 10
  for(int i=0; i<=10; i++){
    cout<< catalan(i)<<" ";
  }
  cout<<endl;
  return 0;
}