#include<iostream>
#include<iomanip>   //for setw()
using namespace std;
int main(){
  int a = 12, b = 234, c = 12323443;
  cout<<"The value of a is : "<<setw(7)<<a<<endl;
  cout<<"The value of b is : "<<setw(5)<<b<<endl;
  cout<<"The value of c is : "<<setw(5)<<c<<endl;

  cout<<endl<<"Operator Precedance"<<endl;
  int x = 34, y = 56;
  int z =  (x*y) + y;
  cout<<"z is : "<<z<<endl<<endl; 
  return 0;
}