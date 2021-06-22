#include<iostream>
using namespace std;

// to check if there is zero or 1 in each bit of binary of a number
int getBit(int n, int pos){
  return (n & (1 << pos)) != 0;
}

// set '1' in the provided bit
int setBit(int n, int pos){
  return (n | (1 << pos));
}

// set '0' to the provided bit
int clearBit(int n, int pos){
  int mask = ~(1 << pos);    // "~" this is for 1's compliment
  return mask & n;
}

int updateBit(int n, int pos, int value){
  n = clearBit(n, pos);
  return (n | (value << pos));
}

int main(){

  // cout<< getBit(5, 2);

  // cout<< setBit(5,1); 

  // cout<< clearBit(5, 2);

  // cout<< updateBit(5, 1, 1);

  return 0;
}