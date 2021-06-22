
/*
example :
8 = 1000
7 = 0111
1000 & 0111 = 0000 (which is 0 in binary and hence 8 is a power of 2)
*/


#include<iostream>
using namespace std;

bool isPowerOf_2(int n){
  return (n && !(n & n-1)); 
}

int main(){
  
  cout<< isPowerOf_2( 16 );

  return 0;
}