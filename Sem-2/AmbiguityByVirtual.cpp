#include<iostream>
using namespace std;
class classA { public: int a; };
class classB: virtual public classA{
  public: int b; };
class classC: virtual public classA{
  public: int c; };
class ChildClass: public classB, public classC{
 public: int child; };
int main(){
  ChildClass* ptr = new ChildClass;
  ptr->a = 100; ptr->b = 200; 
  ptr->c = 400; ptr->child = 500;
  cout<<"Solving ambiguity by virtual methode\n";
  cout<<"Value of a from classA "<<ptr->a<<endl;
  cout<<"Value of b from classB "<<ptr->b<<endl;
  cout<<"Value of c from classC "<<ptr->c<<endl;
  cout<<"Value of child from ChildClass "<<ptr->child<<endl;
  return 0; }