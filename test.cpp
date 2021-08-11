#include<iostream>
#include<stack>
using namespace std;

int main(){
  stack<int> s1;
  stack<int> s2;

  s1.push(1);
  s1.push(2);
  s1.push(3);

  s2.push(5);

  s1.swap(s2);

  cout<<"S1 : ";
  while(!s1.empty()){
    cout<<s1.top()<<" ";
    s1.pop();
  }cout<<endl;

  cout<<"S2 : ";
  while(!s2.empty()){
    cout<<s2.top()<<" ";
    s2.pop();
  }cout<<endl;

  return 0;
}