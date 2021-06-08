
/*
facts about friend function
1. friend function is not a member function.
2. we can not call the friend function through object like "obj.friend_function()".
3. can be declared inside public or public section of the class.
4. usually take the objects arguement.
5. It can not access private member directly. It need sytax "obj.member_Name"
*/


#include<iostream>
using namespace std;

class Complex{
  int a, b;
  public:

    friend Complex sumComplex(Complex, Complex);

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

Complex sumComplex(Complex obj_a, Complex obj_b){
  Complex result;
  result.a = obj_a.a + obj_b.a;
  result.b = obj_a.b + obj_b.b;
  return result;
}

int main(){
  Complex o1, o2;
  o1.setData();
  o1.showData();

  o2.setData();
  o2.showData();

  Complex sum =  sumComplex(o1, o2);
  sum.showData();
  return 0;
}

