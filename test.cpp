#include<iostream>
using namespace std;

void call(int *y){
  static int i = 0;
  if(i == 3) return;
  i++;
  int ano = 0;
  *y = *y + 2;
  call(&ano);
  cout<< ano<<endl;
}

int main(){
  int x = 10;
  call(&x);
  return 0;
}