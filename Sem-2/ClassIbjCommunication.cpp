#include<iostream>
using namespace std;

class firstClass{
  public:
  void show(int ans) { cout<<"The sum is : "<<ans; }  };
class secondClass{
  public:
  int addNumber(int x, int y) { return(x+y); }  };
  
int main(){
  firstClass f;
  secondClass s;
  f.show(s.addNumber(34,65));
  cout<<endl;
  return 0;
}