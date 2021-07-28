#include<iostream>
#include<stack>
using namespace std;

int redundant_paranthesis(string s){

  stack<char> st;
  int count = 0;

  for(int i=0; i<s.length(); i++){
    if(s[i] == ')' && st.top() == '('){
      count++;
      st.pop();
      continue;
    }
    if(s[i] == ')'){
      while(!st.empty() && st.top() != '('){
        st.pop();
      }
      st.pop();
    }
    else{
      st.push(s[i]);
    }
  }

  return count;
}

int main(){
  string s = "((a+b))";

    // (a+(a+b))

  cout<< redundant_paranthesis(s)<<endl;
  return 0;
}