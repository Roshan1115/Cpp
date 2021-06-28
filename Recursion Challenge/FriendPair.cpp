// find the number of ways in which n friend can be single of pair

#include<iostream>
using namespace std;

int frinedPair(int n){
  if(n==0 || n==1 || n==2){
    return n;
  }

  return frinedPair(n-1) + frinedPair(n-2)*(n-1);
}

int main(){
  cout<< frinedPair(4);
  return 0;
}