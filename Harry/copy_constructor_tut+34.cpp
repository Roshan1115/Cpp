
// Every class have its default copy constructor. So even if user don't define any copy constructor then compiler sypplies its own copy constrctor.

#include<iostream>
using namespace std;

class number{
  int a,b;
  public:
    number(){
      a = 0;
      b = 0;
    }
    number(int x,  int y){
      a = x;
      b = y;
    }
    number(number &obj){    // copy constructor
      cout<<"Copy constructor called.\n";
      a = obj.a;
      b = 0;
    }
    void show(){
      cout<<"The value of a is "<< a<<" and b is "<< b<<endl;
    }
};

int main(){
  cout<<"object a\n";
  number a;
  a.show();

  cout<<"object b\n";
  number b(23, 34);
  b.show();

  cout<<"object c\n";
  number c(b);    // copy constructtor invoked
  c.show();

  cout<<"object d\n";
  number d;
  d = b;    //copy constructor NOT invoked
  d.show();

  cout<<"object e\n";
  number e = b;   //copy constructor invoked
  e.show();

  return 0;
}

