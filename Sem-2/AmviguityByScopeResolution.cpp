#include<iostream>
using namespace std;
class classA { public: int ab; };
class classB { public: int ab; };
class childClass: public classA, public classB{
  public: int c;  };
int main(){
  childClass *pobj = new childClass;
  pobj->classA::ab = 100;
  pobj->classB::ab = 200;
  cout<<"Solving amviguity by scope resolution"<<endl;
  cout<<"Value of ab of classA is : "<<pobj->classA::ab<<endl;
  cout<<"Value of ab of classB is : "<<pobj->classB::ab<<endl;
  return 0; }