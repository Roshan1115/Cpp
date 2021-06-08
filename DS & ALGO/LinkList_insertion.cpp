#include<iostream>
using namespace std;

struct node
{
  int data;
  node *next;
};

//......................................................................

node* insertFirst(node *head, int data){
  node *ptr = new node;
  ptr->next = head;
  ptr->data = data;
  return ptr;
}

void insertAt(node *head, int element, int index){
  node *ptr = new node;
  int i = 0;
  while(i != index-1){
    head = head->next;
    i++;
  }
  ptr->next = head->next;
  head->next = ptr;
  ptr->data = element;
}

void insertEnd(node *head, int element){
  node *ptr = new node;
  while(head->next != NULL){
    head = head->next;
  }
  head->next = ptr;
  ptr->data = element;
  ptr->next = NULL;
}

void traversList(node *ptr){
  while(ptr != NULL){
    cout<<"Data is "<<ptr->data<<endl;
    ptr = ptr->next;
  }
}

void insertAfterNode(node *gNode, int element){
  node *ptr = new node;
  ptr->next = gNode->next;
  gNode->next = ptr;
  ptr->data = element;
}

//......................................................................

int main(){
  node *head = new node;
  node *second = new node;
  node *third = new node;

  //linking head to second
  head->data = 33;
  head->next = second;

  // linking second and third nodes;
  second->data = 12;
  second->next = third;

  // linking third node to nulll
  third->data = 45;
  third->next = NULL;

  traversList(head);
  cout<<endl;

  // insert at first
  head = insertFirst(head, 78);
  traversList(head);
  cout<<endl;

  // inserting at a particular index
  insertAt(head, 90, 3);
  traversList(head);
  cout<<endl;

  // inserting at the end
  insertEnd(head, 100);
  traversList(head);
  cout<<endl;

  //inserting after a given node (after second node)
  insertAfterNode(second, 200);
  traversList(head);
  cout<<endl;

  return 0;
}

