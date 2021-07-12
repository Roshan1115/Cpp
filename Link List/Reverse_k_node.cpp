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

node * reverse_k(node *head,int k){
  node *prev = NULL;
  node *curr = head;
  node *next;

  int count = 0;
  while(curr != NULL && count < k){
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
    count++;
  }

  if(next != NULL){
    head->next = reverse_k(next, k);
  }
  return prev;
}


int main(){

  int k;
  cout<<"Enter K ";
  cin>>k;

  node *a = new node(1);
  for(int i=2; i<12; i++){
    insert(a, i);
  }

  display(a);
  cout<<endl;

  cout<<"After reversing "<<k <<" node.\n";
  node *newhead = reverse_k(a, k);
  display(newhead);
  cout<<endl;
  
  return 0;
}