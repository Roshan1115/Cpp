#include<iostream>
#include<fstream>
using namespace std;

int main(){
  fstream file;
  file.open("Read.txt", ios::in);
  if(file){
    cout<<"Filed opened.\n";
  }
  else{
    cout<<"File can not be opened.\n";
  }
  return 0;
}