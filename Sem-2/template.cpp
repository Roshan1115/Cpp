#include<iostream>
using namespace std;

template <typename T>
T add(T x, T y){
  return x+y;
}

int main(){
  cout<< add<int>(2,7)<< endl;
  cout<< add<float>(2.5,7.6);
  return 0;
}