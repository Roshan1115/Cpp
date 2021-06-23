// find two unique numbers that only occur once


#include<iostream>
using namespace std;

bool setbit(int n, int pos){
  return (n & (1<<pos)) != 0;
}

void unique(int arr[], int size){
  int xor_sum = 0;
  for(int i=0; i<size; i++){
    xor_sum = xor_sum^arr[i];
  }
  int setBit = 0;
  int pos = 0;
  int tempXor = xor_sum;

  while(setBit != 1){
    setBit = xor_sum & 1;
    pos++;
    xor_sum = xor_sum >> 1;
  }
  pos--;

  int newXor = 0;
  for(int i=0; i<size; i++){
    if(setbit(arr[i], pos)){
      newXor = newXor ^ arr[i];
    }
  }
  cout<< newXor<< endl;
  cout<< (newXor ^ tempXor) << endl;
}



int main(){
  int arr[] = {1,2,3,1,2,3,5,7};
  unique(arr, 8);
  return 0;
}