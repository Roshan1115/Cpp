#include<iostream>
using namespace std;

int main(){
  string str;
  cin>> str;    // all letters should be small letter
  int arr[26];

  for(int i=0; i<26; i++){
    arr[i] =  0;
  }

  for(int i=0; i<str.size(); i++){
    arr[str[i] - 'a']++;
  }

  int maxrepeat = 0;
  for(int i=0; i<26; i++){
    maxrepeat = max(maxrepeat, arr[i]);
  }
  cout<< maxrepeat<< endl;
  return 0;
}