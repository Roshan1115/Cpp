#include<iostream>
using namespace std;

int check_ones(int n){
  int count = 0;
  while(n){
    count++;
    n = n & n-1;
  }
  return count;
}

int main(){
  
  cout<< check_ones( 5 );

  return 0;
}