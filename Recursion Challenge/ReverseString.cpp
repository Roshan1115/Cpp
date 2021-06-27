#include<iostream>
using namespace std;

void reverse(string str){
  if(str.length() == 0) return;
  string res = str.substr(1);
  reverse(res);
  cout<< res[0];
}

int main(){
  string s;
  cin>> s;
  reverse(s);
  return 0;
}