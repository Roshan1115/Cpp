#include<iostream>
#include<stack>
using namespace std;

bool isBalanced(string s){
  stack<char> st;
  if(s.length() % 2 != 0) return false;
  // cout<<s.length()<<" ";

  for(int i=0; i< s.length(); i++){
    if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
      st.push(s[i]);
    }
    else if(s[i] == ')' && st.top() == '('){
      st.pop();
    }
    else if(s[i] == ']' && st.top() == '['){
      st.pop();
    }
    else if(s[i] == '}' && st.top() == '{'){
      st.pop();
    }
    else{
      return false;
    }
  }

  if(st.empty()) return true;
  else return false;
}

int main(){
  string s1 = "{([])}";
  string s2 = "{([]})";

  cout<< isBalanced(s1)<<endl;
  cout<< isBalanced(s2)<<endl;
  return 0;
}