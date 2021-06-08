#include<iostream>
using namespace std;
class firstClass{
  public:
  int firstElement; };
class secondClass : public firstClass{
  public:
  int secondElement;
  void getData(int a, int b){
    firstElement = a;
    secondElement = b;  }
    void show() { cout<<"FirstClass element "<<firstElement<<endl;
      cout<<"SecondClass Element "<<secondElement; }  };
int main(){
  firstClass f;
  secondClass s;
  s.getData(45,67);
  s.show();
  return 0;
}