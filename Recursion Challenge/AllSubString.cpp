// generate all possible substring using recursion

#include<iostream>
using namespace std;

void allSubString(string s, string ans){
  if(s.length() == 0){
    cout<< ans << endl;
    return;
  }

  allSubString(s.substr(1), ans);
  allSubString(s.substr(1), ans + s[0]);
}

int main(){
  allSubString("ABC", "");
  return 0;
}