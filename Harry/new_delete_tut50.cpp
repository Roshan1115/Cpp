#include<iostream>
using namespace std;

int main(){
  int a = 23;
  int* ptr = &a;
  cout<<"the adress of a is "<<ptr<<endl;
  cout<<"the value of a is "<< *ptr<<endl;


  //same thing we can do without giving a name to the variale
  int* p = new int(23);
  cout<<endl<<"The address of this new integer variavle is "<<p<<endl;
  cout<<"The value of this new intiger variable is "<< *p<<endl;


  //lets make array of integer using new keyword (dynamically)
  int* pArr = new int[4];
  pArr[0] = 877;
  pArr[1] = 457;
  pArr[2] = 856;
  pArr[3] = 56;
  cout<<endl;
  for (int i=0;i<4;i++){
    cout<<"The address of pArr["<<i<<"] is "<<(pArr + i)<<endl;
  }
  for (int j = 0;j<4;j++){
   cout<<"The value of pArr["<<j<<"] is "<<pArr[j]<<endl;
  }


  // We should delete the dynamically allocated memory to free up the memory
  delete[] pArr;
  delete p;
  
  return 0;
}