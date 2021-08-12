#include<iostream>
#include<stack>
using namespace std;

int precedence(char c){
  if (c=='^' || c=='$') return 3;
  else if(c=='*' || c=='/') return 2;
  else if(c=='+' || c=='-') return 1;
  else return -1;
}

string InfixToPostfix(string s){
  string ans;
  stack<char> st;
  for(int i=0; i<s.length(); i++){

    if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
      ans += s[i];
    }

  else if(s[i] == '(') st.push(s[i]);

  else if(s[i] == ')'){
    while(!st.empty() && st.top() != '('){
      ans += st.top();
      st.pop();
    }
    if(!st.empty()) st.pop();
  }

  else{
    while(!st.empty() && precedence(st.top()) > precedence(s[i])){
      ans += st.top();
      st.pop();
      }
    st.push(s[i]);
    }
  }

  while(!st.empty()){
    ans += st.top();
    st.pop();
  }

  return ans;
}

int main(){
  string s;
  cout<<"Enter string : ";
  cin>>s; 
  cout<<InfixToPostfix(s)<<endl;

  return 0;
}