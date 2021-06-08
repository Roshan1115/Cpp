#include<iostream>
#include<fstream>
using namespace std;

int main(){
  fstream file;
  file.open("output.txt", ios::out);
  if(file){
    file<< "Hello world !";
  }
  return 0;
}