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


// reverse in iterative way
node * reverse_Iteration(node *head){
  node *prev = NULL;
  node *current = head;
  node *nextptr;

  while(current != NULL){
    nextptr = current->next;
    current->next = prev;

    prev = current;
    current = nextptr;
  }

  return prev;
}


node * reverse_recursion(node *head){

  if(head == NULL || head->next == NULL){
    return head;
  }

  node *newHead = reverse_recursion(head->next);
  head->next->next = head;
  head->next = NULL;

  return newHead;
}


int main(){

  node *a = new node(1);
  for(int i=2; i<10; i++){
    insert(a, i);
  }

  display(a);
  cout<<endl;

  
  cout<<"After reversing by iteration."<<endl;
  node *newHead = reverse_Iteration(a);
  display(newHead);

  cout<<endl;
  cout<<"Again reversing with recursive way.\n";
  node *newRecurHead = reverse_recursion(newHead);
  display(newRecurHead);
  return 0;
}