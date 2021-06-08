#include<iostream>
using namespace std;

// Forward declaration
class Complex;

class Calculator{
  public:
    void SumComplex(Complex, Complex);
    void sumReal(Complex, Complex);
    void sumImaginary(Complex, Complex);
};

class Complex{
  int a, b;
  public:

    // Declaring friend function individually
    // friend void Calculator ::SumComplex(Complex, Complex);
    // friend void Calculator :: sumReal(Complex, Complex);
    // friend void Calculator :: sumImaginary(Complex, Complex);

    // Declaring all funtiion of calculator as friend
    friend class Calculator;

    void setData(){
      int n1,n2;
      cout<<"Enter value of a and b\n";
      cin>>n1>>n2;
      a = n1; b = n2;
    }
    void showData(){
      cout<<"Value of your complex number is : "<<a<<" + "<<b<<"i\n";
    }
};


void Calculator :: SumComplex(Complex obj_a, Complex obj_b){
  Complex result;
  result.a = obj_a.a + obj_b.a;
  result.b = obj_a.b + obj_b.b;
  cout<<"The sum of complex number is "<<result.a<<" + "<<result.b<<"i"<<endl;
}
void Calculator :: sumReal(Complex o1, Complex o2){
  int result = o1.a + o2.a;
  cout<<"The sum of real part is "<<result<<endl;
}
void Calculator :: sumImaginary(Complex o1, Complex o2){
  int result = o1.b + o2.b;
  cout<<"The sum of imaginary part is "<<result<<endl;
}



int main(){
  Complex object1, object2;
  object1.setData();
  object2.setData();

  object1.showData();
  object2.showData();

  Calculator calculate;
  calculate.SumComplex(object1, object2);
  calculate.sumReal(object1, object2);
  calculate.sumImaginary(object1, object2);
 
  return 0;
}
