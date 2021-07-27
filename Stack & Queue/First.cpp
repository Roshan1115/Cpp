#include<iostream>
using namespace std;

#define n 100

class stack{
  int *arr;
  int top;

  public:
  stack(){
    arr = new int[n];
    top = -1;
  }

  void push(int val){
    if(top == n-1){
      cout<<"Stack Overflow.\n";
      return;
    }
    top++;
    arr[top] = val;
  }

  void pop(){
    if(top == -1){
      cout<<"No element to delete.\n";
      return;
    }
    top--;
  }

  int Top(){
    if(top == -1){
      cout<<"No element.\n";
      return -1;
    }
    return arr[top];
  }

  bool empty(){
    return top == -1;
  }

};



int main(){
  stack st;
  st.push(10);
  st.push(20);
  st.push(30);
  st.push(40);
  cout<<st.Top()<<endl;;
  st.pop();
  cout<<st.Top()<<endl;
  return 0;
}