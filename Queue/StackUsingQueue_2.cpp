// this make pop costly and push eassy

#include<iostream>
#include<queue>
using namespace std;

class stack{
  queue<int> q1;
  queue<int> q2;
  int N;

  public:
  stack(){
    N = 0;
  }


  void push(int val){
     q1.push(val); 
     N++; 
  }

  void pop(){
    while(q1.size() != 1){
      q2.push(q1.front());
      q1.pop();
    }
    q1.pop();
    q1.swap(q2);
    N--;
  }

  int top(){
    return q1.back();
  }

  int size(){
    return N;
  }
   
};

int main(){
  stack st;
  st.push(1);
  st.push(2);
  st.push(3);
  st.push(4);
  st.push(5);

  cout<< st.top()<<" "<< st.size()<< endl;

  st.pop();

  cout<< st.top()<<" "<< st.size()<< endl;
  return 0;
}