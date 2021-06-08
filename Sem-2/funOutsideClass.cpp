#include<iostream>
using namespace std;

class randomClass{
  public:
  void show();
};
void randomClass::show(){
  cout<<"This function is defined outside the class.";
}
int main(){
  randomClass c;
  c.show();
  return 0;   }