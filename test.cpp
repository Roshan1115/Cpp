#include<iostream>
using namespace std;

void call2(int *y){
  *y += 2;
}

void call(){
  int x;
  x = 23;
  call2(&x);
  cout<< x<< endl;
}

int main(){
  call();
  return 0;
}