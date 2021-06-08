#include<iostream>
using namespace std;

struct node{
  int data;
  node *next;
};

void displayAll(node *head){
  while(head != NULL){
    cout<<head<<" "<<head->data<<endl;
    head = head->next;
  }cout<<endl; 
}

node * deleteFirst(node *head){
  node *ptr = head;
  head = head->next;
  delete ptr;
  return head;
}

void deleteAt(node *head, int index){
  for(int i = 0; i < index-1; i++){
    head = head->next;
  }
  node *ptr = head->next;
  head->next = head->next->next;
  delete ptr;
}

void deleteLast(node *head){
  while(head->next->next != NULL){
    head = head->next;
  }
  node *ptr = head->next;
  head->next = NULL;
  delete ptr;
}

void deleteElement(node *head, int element){
  while(head->next != NULL && head->next->data != element){
    head = head->next;
  }
  if(head->next != NULL){
    node *ptr = head->next;
    head->next = head->next->next;
    delete ptr;
  }
  else{
      cout<<"Element not found.\n\n";
    }
}

int main(){
  node *first = new node;
  node *second = new node;
  node *third= new node;
  node *fourth = new node;
  node *fifth = new node;
  node *sixth = new node;
  node *seventh = new node;
  node *eitghth = new node;
  node *ninth = new node;

  first->data = 10;
  first->next = second;

  second->data = 20;
  second->next = third;

  third->data = 30;
  third->next = fourth;

  fourth->data = 40;
  fourth->next = fifth;

  fifth->data = 50;
  fifth->next = sixth;

  sixth->data = 60;
  sixth->next = seventh;

  seventh->data = 70;
  seventh->next = eitghth;

  eitghth->data = 80;
  eitghth->next = ninth;

  ninth->data = 90;
  ninth->next = NULL;

  displayAll(first);

  // Deleting first node
  // first = deleteFirst(first);
  // displayAll(first);

  // delete eleent of an index
  // deleteAt(first, 5);
  // displayAll(first);

  // Delete last element
  // deleteLast(first);
  // displayAll(first);

  // Delete given element
  deleteElement(first, 70);
  displayAll(first);

  return 0;
}