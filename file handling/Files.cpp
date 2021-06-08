#include<iostream>
#include<fstream>
using namespace std;

int main(){
  fstream f;
  f.open("my_File.txt", ios::in);
  if(! f){
    cout<<"Not created\n";
  }
  else{
    cout<<"File created successfully.\n";
  }
  f.close();
  return 0;
}