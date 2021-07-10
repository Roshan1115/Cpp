#include<iostream>
using namespace std;

class node{
  public:
  int data;
  node *next;

  node(int value){
    data = value;
    next = NULL;
  }
};

void display(node *head){

  while( head != NULL){
    cout<<head->data<<" -> ";
    head = head->next;
  }
  cout<<"NULL";
  cout<<endl;
}

void insert(node *head, int value){
  if(head == NULL){
    head->data = value;
    return;
  }

  node *temp = head;
  while(temp->next != NULL){
    temp = temp->next;
  }
  node *n = new node(value);
  temp->next = n;
}

int main(){

  node *a = new node(1);
  for(int i=2; i<10; i++){
    insert(a, i);
  }

  display(a);
  return 0;
}