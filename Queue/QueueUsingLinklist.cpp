#include<iostream>
using namespace std;

class node{
  public:
  int data;
  node *next;

  node(int val){
    data = val;
    next = NULL;
  }
};

class queue{
  node* front;
  node* back;

  public:
  queue(){
    front = NULL;
    back = NULL;
  }

  bool empty(){
    return(front == NULL);
  }

  void push(int val){
    if(this->empty()){
    front = new node(val);
    back = front;
    return;
    }
    back->next = new node(val);
    back = back->next;
  }

  void pop(){
    if(this->empty()){
      cout<<"No elements in queue.\n";
      return;
    }
    node *p = front;
    front = front->next;
    delete p;
  }

  int peek(){
    if(this->empty()){
      cout<<"No elements in queue.\n";
      return -1;
    }
    return front->data;
  }

};

int main(){
  queue q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);

  cout<<q.peek()<<endl; q.pop();
  cout<<q.peek()<<endl; q.pop();
  cout<<q.peek()<<endl; q.pop();
  cout<<q.peek()<<endl; q.pop();

  return 0;
}