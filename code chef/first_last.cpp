#include<iostream>
using namespace std;

int main(){
  int t;
  cin>> t;
  while(t--){
    string s, fele, lele;
    cin>> s;
    fele = s[0];
    lele = s[s.length() - 1];
    cout<< stoi(fele) + stoi(lele)<< endl;
  }

  return 0;
}