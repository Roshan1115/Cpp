// move all 'x' to the last of a given string

#include<iostream>
using namespace std;

string LastX(string s){
  if(s.length() == 0){
     return "";
  }
  char ch = s[0];
  string ans = LastX(s.substr(1));

  if(ch == 'x'){
    return ans + ch;
  }
  return ch + ans;

}

int main(){
  string s;
  cin>> s;
  cout<< LastX(s);
  return 0;
}