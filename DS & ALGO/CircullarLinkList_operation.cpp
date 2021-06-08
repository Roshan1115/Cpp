#include<iostream>
using namespace std;
struct node{
  int data;
  node *next;
};

void traverseList(node *head){
  node *ptr = head;
  do
  {
    cout<<ptr<<" "<<ptr->data<<endl;
    ptr = ptr->next;
  } while (ptr != head);
  cout<<endl;
}

node * insertFirst(node *head, int element){
  node *ptr = new node;
  ptr->data = element;
  ptr->next = head;

  while(head->next != ptr->next){
    head = head->next;
  }
  head->next = ptr;
  return ptr;
}

int main(){
  node *first = new node;
  node *second = new node;
  node *third = new node;
  node *fourth = new node;

  first->data = 33;
  first->next = second;

  second->data = 12;
  second->next = third;

  third->data = 45;
  third->next = fourth;

  fourth->data = 87;
  fourth->next = first;

  traverseList(first);

  // inserting at first 
  first = insertFirst(first, 85);
  traverseList(first);
  return 0;
}