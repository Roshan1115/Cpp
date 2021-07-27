/* This algorithm makes oush method easy and pop method costly */


#include<iostream>
#include<stack>
using namespace std;

class queue{
  public:
  stack<int> st;

  void push(int x){
    st.push(x);
  }

  void POP(){
    int x = st.top();
    st.pop();
    if(st.empty()) return;

    POP();

    st.push(x);
  }

};



int main(){
  queue q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  q.push(5);

  q.POP();

  while(!q.st.empty()){
    cout<<q.st.top()<<" ";
    q.st.pop();
  }

  return 0;
}