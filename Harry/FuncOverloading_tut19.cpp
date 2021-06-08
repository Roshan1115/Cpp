#include<iostream>
using namespace std;

// two function using same name but havving different arguements

int add(int a, int b){ 
  cout<<"Using only two argument function\n";
  return a+b;
}
int add(int a, int b, int c){
  cout<<"Using three arguement function.;\n";
  return a+b+c;
}

int main(){
  cout<<"the vale of 3+5 is "<<endl<<add(3,5)<<endl; 
  cout<<"the vale of 3+5+7 is "<<endl<<add(3,5,7)<<endl; 
  return 0;
}