#include<iostream>
using namespace std;

class base{
  public:
     void show(){
      cout<<"Inside the base class.\n";
    }
};
class derived : public base {
  public:
     void show(){
      cout<<"Inside the derived class.\n";
    }
};
int main(){
  derived d;
  d.show();
  return 0;
}