#include<iostream>
using namespace std;

int main(){
  int a = 50;
  int *b = &a;
  int *c = b;
  *c += 10;
  cout<< a;
  return 0;
}