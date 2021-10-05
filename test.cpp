#include<iostream>
using namespace std;

int give(int a){
  if(a == 1)
    return 100;
  int p;
  return p = give(a-1);
}

int main(){
  cout<< give(3) << endl;
  return 0;
}

// use : g++ -std=c++11 