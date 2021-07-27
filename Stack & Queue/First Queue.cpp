#include<iostream>
using namespace std;

#define n 20

class queue{
  int *arr;
  int front;
  int back;

  public:
  queue(){
    arr = new int[n];
    front = -1;
    back = -1;
  }

  bool empty(){
    if(front == -1 || front > back) return true;
    else return false;
  }

  void push(int val){
    if(back == n-1){
      cout<<"Queue overflow.\n";
      return;
    }
    back++;
    arr[back] = val;
    if(front == -1) front++;
  }

  void pop(){
    if(this->empty()){
      cout<<"No elements in queue.\n";
      return;
    }
    front++;
  }

  int peek(){
    if(this->empty()){
      cout<<"No elements in queue.\n";
      return -1;
    }
    return arr[front];
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