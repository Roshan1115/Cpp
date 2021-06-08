#include<iostream>
using namespace std;

int main(){
  int a,b;
  cout<<"Enter a ";
  cin>>a;
  cout<<"Enter b ";
  cin>>b;

  try
  {
    if(b == 0){
      throw ("b can not be 0.");
    }
    else{
      int c = a/b;
      cout<<"The quotent is "<< c;
    }
  }
  catch(const char *c)
  {
    cout<< c;
  }
  
  return 0;
}