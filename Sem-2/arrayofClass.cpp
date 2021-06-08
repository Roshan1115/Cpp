#include<iostream>
using namespace std;
class myClass{
  int x;
  public:
  void getx(int i) { x = i; }
  int showx() { return x; }   };
int main(){
  myClass obj[4];
  for (int i = 0; i < 4; i++) { obj[i].getx(i); }
  for (int i = 0; i < 4; i++){
    cout<<"Object of Class "<<i<<", x value is : "<<obj[i].showx();
    cout<<endl;   }
  return 0;   }