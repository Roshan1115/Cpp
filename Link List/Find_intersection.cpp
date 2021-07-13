// find the intersection point of two link list


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

int length(node *head){
  int l=1;
  while(head->next != NULL){
    head = head->next;
    l++;
  }
  return l;
}

node* findIntersection(node *head1, node *head2){
  int l1 = length(head1);
  int l2 = length(head2);
  int diff, count = 0;

  if(l1>l2){
    diff = l1-l2;
    while(count != diff && head1->next != NULL){
      head1 = head1->next;
      count++;
    }
    while(head1 != head2 && head1->next != NULL && head2->next != NULL){
      head1 = head1->next;
      head2 = head2->next;
    }
    if(head1 == head2) return head1;
    else return NULL;
  }

  else if(l2>l1){
    diff = l2-l1;
    while(count != diff && head2->next != NULL){
      head2 = head2->next;
      count++;
    }
    while(head1 != head2 && head1->next != NULL && head2->next != NULL){
      head1 = head1->next;
      head2 = head2->next;
    }
    if(head1 == head2) return head1;
    else return NULL;
  }
  else{
    while(head1 != head2 && head1->next != NULL && head2->next != NULL){
      head1 = head1->next;
      head2 = head2->next;
    }
    if(head1 == head2) return head1;
    else return NULL;
  }
}

int main(){

  // first link list
  node *a = new node(1);
  node *b = new node(2);
  node *c = new node(3);
  node *d = new node(4);
  node *e = new node(5);
  node *f = new node(6);

  a->next = b; b->next = c; c->next = d; d->next = e;
  e->next = f; f->next = NULL;

  // second link list
  node *x = new node(10);
  node *y = new node(15);

  x->next = y; y->next = e;
 
  cout<<"First link list.\n";
  display(a);
  cout<<"second link list.\n";
  display(x);

  node *intersection_point = findIntersection(a, x);
  if(intersection_point != NULL){
    cout<<"The intersection point or node is ";
    cout<<intersection_point->data<<endl;
  }
  return 0;
}