// replace every 'pi' with 3.14 in a given string

#include<iostream>
using namespace std;

void replacePi(string s){
  if(s.length() == 0)  return;

  if(s[0] == 'p' && s[1] == 'i'){
    cout<< "3.14";
    s = s.substr(2);
  }
  else{
    cout<< s[0];
    s = s.substr(1);
  }
  replacePi(s);
}

int main(){
  string s;
  cin>> s;
  replacePi(s);
  return 0;
}