// remove the adjacent dubplicate from string using resursion

#include<iostream>
using namespace std;

void removeDuplicate(string s){
  if(s.length() == 0){
    return; // base case
  }
  if(s[0] == s[1]){
    removeDuplicate(s.substr(1));
  }
  else{
    cout<< s[0];
    removeDuplicate(s.substr(1));
  }
}

int main(){
  string s;
  cin>> s;
  removeDuplicate(s);
  return 0;
}