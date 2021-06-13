#include<iostream>
using namespace std;

// largets word in a sentence

int main(){
  int n;
  cin>>n;
  char sentence[n+1];

  cin.ignore();
  cin.getline(sentence, n);  // predefined function in c++ to get a line
  // cin.ignore();  // to clear the buffer after a line.

  int i=0;
  int len = 0, maxLen = 0;
  int st = 0;

  while( sentence[i] != '\0' ){
    if( sentence[i] == ' ' )  {
      len = 0;
    }
    else {
      len++;
    }
    if(len > maxLen){
      maxLen = len;
      st = i - (len-1);
    }
    i++;
  }

  cout<< maxLen<< endl;
  for(int i=st; i< (st+maxLen); i++){
    cout<<sentence[i];
  }
  return 0;
}