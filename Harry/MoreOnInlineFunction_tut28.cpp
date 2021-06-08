#include<iostream>
using namespace std;

class y;
class x{
  int data;
  public:
    void setData(int value){
      data = value;
    }
    friend void swap(x &,y &);

    void display(){
      cout<<"value of class x data is "<<data<<endl;
    }
};
class y{
   int data;
  public:
    void setData(int value){
      data = value;
    }
    friend void swap(x &,y &);

    void display(){
      cout<<"value of class y data is "<<data<<endl;
    }
};

void swap(x &a, y &b){
  int temp = a.data;
  a.data = b.data;
  b.data = temp;
}
int main(){
  x a;
  y b;
  a.setData(23);
  b.setData(45);
  swap(a,b);

  a.display();
  b.display();
  return 0;
}