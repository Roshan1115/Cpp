//append last k node of a link list to the starting of that link list

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

int length(node *head){
  int l=1;
  while(head->next != NULL){
    head = head->next;
    l++;
  }
  return l;
}

void append_k_node(node * &head, int k){
  int count = 1;
  int l = length(head);
  node *temp = head;
  while(count != l-k){
    temp = temp->next;
    count++;
  }
  node *secondTemp = temp->next;
  temp->next = NULL;
  temp = secondTemp;
  while(temp->next != NULL){
    temp = temp->next;
  }
  temp->next = head;
  head = secondTemp;
}

int main(){

  node *a = new node(1);
  for(int i=2; i<10; i++){
    insert(a, i);
  }

  display(a);
  
  int k;
  cout<<"\nEnter K ";
  cin>> k;
  append_k_node(a, k);
  display(a);
  return 0;
}