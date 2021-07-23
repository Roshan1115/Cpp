/*
1. reverse the given string
2. convert opening braces to closing and vice versa
3. apply infix to postfix algorithm
4. reverse the final result and return
*/

#include<iostream>
#include<stack>
#include<math.h>
using namespace std;

int precedence(char ch){
  if(ch == '^') return 3;
  if(ch == '*' || ch == '/') return 2;
  if(ch == '+' || ch == '-') return 1;
  else return -1;
}

string infixToPrifix(string s){
  reverse(s.begin(), s.end());
  
  for(int i=0; i<s.length(); i++){
    if(s[i] == '(') s[i] = ')';
    else if(s[i] == ')') s[i] = '(';
  }


  stack<char> st;
  string res;
  for(int i=0; i<s.length(); i++){
    if(s[i] >= 'a' && s[i] <= 'z'){
      res += s[i];
    }
    else if(s[i] == '(')  st.push(s[i]);

    else if(s[i] == ')'){
      while(!st.empty() && st.top() != '('){
        res += st.top();
        st.pop();
      }
      st.pop();
    }
    else{   // operator
      while(!st.empty() && precedence(st.top()) > precedence(s[i])){
        res += st.top();
        st.pop();
      }
      st.push(s[i]);
    }
  }

  while(!st.empty()){
    res += st.top();
    st.pop();
  }

  reverse(res.begin(), res.end());
  return res;
}

int main(){
  string s = "(a-b/c)*(a/k-l)";
  cout<< infixToPrifix(s);
  return 0;
}