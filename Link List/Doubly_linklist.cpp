#include<iostream>
using namespace std;

class node{
  public:
  int data;
  node *prev;
  node *next;
  node(int value){
    data = value;
    prev = NULL;
    next = NULL;
  }
};

void insert_first(node * &head, int value){
  node *n = new node(value);
  n->next = head;
  if(head != NULL)  head->prev = n;
  head = n;
}

void insert_tail(node * &head, int value){
  
  if(head == NULL){
    insert_first(head, value);
    return;
  }

  node *n = new node(value);
  node *temp = head;
  while(temp->next != NULL){
    temp = temp->next;
  }
  temp->next = n;
  n->prev = temp;

}

void display(node *head){

  while( head != NULL){
    cout<<head->data<<" -> ";
    head = head->next;
  }
  cout<<"NULL";
  cout<<endl;
}

void deletion(node * &head, int pos){
  node *temp = head;

  // for deleting first node
  if(pos == 1){
    head->next->prev = NULL;
    head = head->next;
    delete temp;
    return;
  }

  int count = 1;
  node *behindTemp;
  while(temp != NULL && count< pos){
    behindTemp = temp;
    temp = temp->next;
    count++;
  }

  // for deleting last node 
  if(temp->next == NULL && count == pos){
    behindTemp->next = NULL;
    delete temp;
    return;
  }

  temp->prev->next = temp->next;
  temp->next->prev = temp->prev;
  delete temp;
}

int main(){
  node *a = NULL;
  for(int i=1; i<11; i++){
    insert_tail(a, i*10);
  }

  display(a);
  cout<<endl;

  insert_first(a, 0);

  display(a);

  int pos;
  cout<<"Enter position starting from 1 to 11. ";
  cin>> pos;

  deletion(a, pos);
  display(a);
  return 0;
}