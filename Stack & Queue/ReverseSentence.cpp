#include<iostream>
#include<stack>   // for stack using
using namespace std;

void reverseSen(string s){
  stack<string> st;

  for(int i=0; i<s.length(); i++){
    string word = "";
    while(s[i] != ' ' && i<s.length()){
      word = word + s[i];
      i++;
    }
    st.push(word);
  }

  while( ! st.empty()){
    cout<<st.top()<<" ";
    st.pop();
  }
}


int main(){
  string s = "hey, how are you doing?";
  reverseSen(s);
  return 0;
}