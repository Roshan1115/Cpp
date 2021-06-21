// form the greatest number provided in a string

#include<iostream>
using namespace std;

int main(){
  string str = "34982387";

  sort(str.begin(), str.end(), greater<int>());

  cout<< str<< endl;
  return 0;
}