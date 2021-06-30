#include<iostream>
using namespace std;

template <class T>
T add(T x, T y){
  return x+y;
}

int main(){
  cout<< add(2,7)<< endl;
  cout<< add(2.5,7.6);
  return 0;
}