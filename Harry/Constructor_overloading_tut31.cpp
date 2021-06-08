#include<iostream>
using namespace std;

class myNumber{
  int a,b;
  public:
    myNumber(){
      a = 0;
      b = 0;
    }
    myNumber(int x, int y){
      a = x;
      b = y;
    }
    myNumber(int x){
      a = x;
      b = 0;
    }
    void showData(){
      cout<<"Value of a and b are "<< a << " "<< b << endl;
    }
};

int main(){
  myNumber a;
  a.showData();

  myNumber b(12);
  b.showData();

  myNumber c(34,65);
  c.showData();

  return 0;
}