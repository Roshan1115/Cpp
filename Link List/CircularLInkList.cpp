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

void displayCircular(node *head){

  node *temp = head;
  do{
    cout<<temp->data<<" -> ";
    temp = temp->next;

  }while(temp != head);

  cout<<"Repeat"<<endl;
}


void insert_head(node * &head, int val){
  node *newnode = new node(val);
  if(head == NULL){
    head = newnode;
    head->next = head;
    return;
  }

  node* temp = head;
  while(temp->next != head){
  temp = temp->next;
  }

  temp->next = newnode;
  newnode->next = head;
  head = newnode;

}

void insert_last(node* &head, int n){

  node *temp = head;
  while(temp->next != head){
    temp = temp->next;
  }
  node *newNode = new node(n);
  temp->next = newNode;
  newNode->next = head;
}

void delete_last(node* &head){
  node *temp = head;
  while(temp->next->next != head){
    temp = temp->next;
  }
  delete temp->next;
  temp->next = head;

}


void delete_first(node* &head){
  node *temp = head;
  node *todelete = head;
  while(temp->next != head){
    temp = temp->next;
  }
  temp->next = head->next;
  head = head->next;
  delete todelete;
}

int main(){

  node *a = new node(1);
  node *b = new node(2);
  node *c = new node(3);
  node *d = new node(4);
  node *e = new node(5);
  node *f = new node(6);

  a->next = b;
  b->next = c;
  c->next = d;
  d->next = e;
  e->next = f;
  f->next = a;

  displayCircular(a);
  
  cout<<endl<<"insert at last.\n";
  insert_last(a, 7);
  displayCircular(a);

  cout<<endl<<"Insert at first.\n";
  insert_head(a, 8);
  displayCircular(a);

  cout<<"\nDelete last.\n";
  delete_last(a);
  displayCircular(a);

  cout<<"\nDelete first.\n";
  delete_first(a);
  displayCircular(a);

  cout<<endl;
  return 0;
}