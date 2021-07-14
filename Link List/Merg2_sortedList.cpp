// merge 2 sorted link list

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


// merge function (iteratibe)
node * merge(node* &a, node* &b){
  node *ptr1 = a;
  node *ptr2 = b;

  node *dummy = new node(0);
  node *temp = dummy;
  while(ptr1 != NULL && ptr2 != NULL){
    if(ptr1->data > ptr2->data){
      dummy->next = ptr2;
      dummy = dummy->next;
      ptr2 = ptr2->next;
    }
    else{
      dummy->next = ptr1;
      dummy = dummy->next;
      ptr1 = ptr1->next;
    }
  }

  while(ptr1 != NULL){
    dummy->next = ptr1;
    dummy = dummy->next;
    ptr1 = ptr1->next;
  }
  while(ptr2 != NULL){
    dummy->next = ptr2;
    dummy = dummy->next;
    ptr2 = ptr2->next;
  }

  node *todelete = temp;
  temp = temp->next;
  delete todelete;
  return temp;
}


// merge function (recursive)
node * mergeRecursive(node * &a, node* &b){

  if(a == NULL) return b;
  if(b == NULL) return a;

  node *ptr1 = a;
  node *ptr2 = b;
  node *result;

    if(ptr1->data > ptr2->data){
      result = ptr2;
      result->next = mergeRecursive(ptr1, ptr2->next);
    }
    else{
      result = ptr1;
      result->next = mergeRecursive(ptr1->next, ptr2);
    }
  
  return result;
}

int main(){

  node *first = new node(1);
  for(int i=3; i<20; i += 2){
    insert(first, i);
  }

  node *second = new node(2);
  for(int i=4; i<20; i += 2){
    insert(second, i);
  }

  display(first);
  display(second);

  cout<<"After merging both list. \n";
  // node *merged = merge(first, second);
  
  node *mergedRecursive = mergeRecursive(first, second);

  display(mergedRecursive);

  return 0;
}