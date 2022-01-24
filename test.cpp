#include<iostream>
using namespace std;

class test{

  public:
  int x;
  test(){
    cout<<"Constructor.\n";
    this->x = 0;
  }
  test(int y){
    this->x = y;
    cout<<"parameter.\n";
  }
};

int main(){
  test obj;

  obj(78);
  cout<< obj.x<<endl;


  return 0;
  }

// use : g++ -std=c++11 