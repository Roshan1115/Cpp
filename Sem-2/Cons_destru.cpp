#include<iostream>
using namespace std;
class firstClass{
  public:
  firstClass() { cout<<"Constructor of firstClass called."<<endl; }
  ~firstClass() { cout<<"Destructor of firstclass called."<<endl; } };
int main(){
  firstClass f;
  cout<<"Hellow world."<<endl;
  return 0; }