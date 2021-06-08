#include<iostream>
using namespace std;
class firstClass{
  public:
    class secondClass{
      public:
      void showSomething(){
        cout<<"Inside the nested class.\n";
      }
    };
    void showSomething(){
      cout<<"inside the first class.\n";
    }
};
int main(){
  firstClass f;
  f.showSomething();
  firstClass::secondClass s; 
  s.showSomething();
  return 0;
}