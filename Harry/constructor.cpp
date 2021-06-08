/*
1. Constructor is automatically invoked whenn object of class is created.
2. Constructor can not return a value and they do not have any return type.
3. We can not reffer to their adderess.
*/

#include<iostream>
using namespace std;

class Complex{
  int a,b;
  public:
    Complex(){  //default constructor
      a = 0;
      b = 0;
    }

    Complex(int x, int y){  // Parameterized counstructor
      a = x;
      b = y;
    }

    void show(){
      cout<<"The values of a and b are "<< a <<" and " << b << endl;
    }
};

int main(){
  // Calling default constructor : 
  Complex a;
  a.show();

  // calling parameterized cunstructor :   
  Complex b(12, 45);  // implicit call
  Complex c = Complex(12, 45);  // Explicit call
  b.show();
  c.show();
  
  return 0;
}