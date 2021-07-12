// to remove cycle from a link list we again use floyed's algorithm

// for detection of cycle in a linklist we use floyed's algorithm
// in this we have a slow pointer and a first pointer
// slow moves in one step and first in two step
// if there is a cycle and both pointers will meet surely



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

void removeCycle(node *head){
  node *fast = head;
  node *slow = head;

  while(fast != NULL && fast->next != NULL){
    slow = slow->next;
    fast = fast->next->next;

    if(slow == fast){
      fast = head;
      while(fast->next != slow->next){
        fast = fast->next;
        slow = slow->next;
      }
      slow->next = NULL;
      break;
    }

  }
}

int main(){

  node *a = new node(1);
  node *b = new node(2);
  node *c = new node(3);
  node *d = new node(4);
  node *e = new node(5);

  a->next = b; b->next = c; c->next = d; d->next = e;
  e->next = b;

 
  cout<<"After removing cycle.\n";
  removeCycle(a);
  display(a);

  return 0;
}