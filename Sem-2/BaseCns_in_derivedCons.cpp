#include<iostream>
using namespace std;
class classA { public: classA(){
  cout<<"Inside the base class constructoor.\n";  }};
class childclass: public classA{
  public: childclass(){
  cout<<"Inside derived class constructor.\n";  }};
int main(){
  childclass ch;
  return 0; }