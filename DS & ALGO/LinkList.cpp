#include<iostream>
using namespace std;

struct Node{
  int data;
  struct Node *next;
};

void traversList(struct Node *ptr){
  while(ptr != NULL){
    cout<<"Data is "<<ptr->data<<endl;
    ptr = ptr->next;
  }
}

int main(){
  struct Node *head, *second, *third;

  // Alocating memory in heap
  head = (struct Node *) malloc(sizeof(struct Node));
  second = (struct Node *) malloc(sizeof(struct Node));
  third = (struct Node *) malloc(sizeof(struct Node));

  // linking first and second nodes;
  head->data = 33;
  head->next = second;

  // linking second and third nodes;
  second->data = 12;
  second->next = third;

  // linking third node to nulll
  third->data = 45;
  third->next = NULL;

  traversList(head);
  return 0;
}     

