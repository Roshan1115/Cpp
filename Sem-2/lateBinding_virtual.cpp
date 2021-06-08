#include<iostream>
using namespace std;

class base{
  public:
     void show(){
      cout<<"Inside base class.\n";
    }
    virtual void print(){
      cout<<"print funciton in base class.\n";
    }
};
class derived : public base{
  public:
    void show(){
      cout<<"Inside derived class.\n";
    }
    void print(){
      cout<<"print funciton in derived class.\n";
    }
};
int main(){
  base *b = new derived;
  b->show();
  b->print();
  return 0;
}