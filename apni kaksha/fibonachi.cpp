#include<iostream>
using namespace std;

void fib(int num){
  int t1 = 0;
  int t2 = 1;
  int nextTerm;
  for(int i = 0; i < num; i++){
    cout<<t1<<" ";
    nextTerm = t1 + t2;
    t1 = t2;
    t2 = nextTerm;
  }
}

int main(){
  int n;
  cout<<"Enter how many terms of fibonacci number you want.\n";
  cin>>n;

  fib(n);
  return 0;
}