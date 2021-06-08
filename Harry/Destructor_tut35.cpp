#include<iostream>
using namespace std;

class num{
  static int count;
  public:
    num(){
      count++;
      cout<<"This is the constructor of class object number "<< count<<endl;
    }
    ~num(){
      cout<<"This is destructor called"<<endl;
      count--;
    }
};

int num :: count = 0;

int main(){
  num n1;

  {
    cout<<"entering a block.\n";
    num n2,n3;
    cout<<"exiting the block.\n";
  }
  cout<<"Back to main function.\n";

  return 0;
}