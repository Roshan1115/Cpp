#include<iostream>
using namespace std;

class Complex{
  int a,b;
  public:
  void getData(){
    cout<<"Enter values of a and b\n";
    cin>>a>>b;
  }
  void showData(){
    cout<<"Values of a and b are "<<a<<" "<<b<<endl;
  }
  void assignData(Complex o1, Complex o2){
    a = o1.a + o2.a;
    b = o1.b + o2.b;
  }
};

int main(){
  Complex obj1, obj2, obj3;
  obj1.getData();
  obj1.showData();

  obj2.getData();
  obj2.showData();

  obj3.assignData(obj1, obj2);
  obj3.showData();
  return 0;
}