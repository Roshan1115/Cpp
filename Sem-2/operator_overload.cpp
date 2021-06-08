#include<iostream>
using namespace std;

class myOperator{
  public:
    void operator -(){
      cout<<"Inside the defination of operator funciton defination.\n";
    }
};
int main(){
  myOperator o;
  -o;
  return 0;
}