#include<iostream>
using namespace std;

void find(){
  cout<<"hello\n";
  
  int *x = new int(4);

  cout<< *x << endl;
}

int main(){
  
  find();

  cout<< *x << endl;
  return 0;
}

// use : g++ -std=c++11 