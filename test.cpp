// #include<iostream>
// using namespace std;

// class node{
//   public:
//   int data;
//   node *next;

//   node(int value){
//     data = value;
//     next = NULL;
//   }
// };

// void display(node *head){

//   while(head != NULL){
//     cout<<head->data<<" ";
//     head = head->next;
//   }
//   cout<<endl;
// }

// void insert(node *head, int value){
//   if(head == NULL){
//     head->data = value;
//     return;
//   }

//   node *temp = head;
//   while(temp->next != NULL){
//     temp = temp->next;
//   }
//   node *n = new node(value);
//   temp->next = n;
// }

// int main(){
//   node *first = new node(12);
//   for(int i=1; i<10; i++){
//     insert(first, i);
//   }
//   display(first);
//   display(first);
//   return 0;
// }











#include<iostream>
using namespace std;

int main(){
  int a = 50;
  int *p = &a;
  int **q = &p;

  cout<< p<<endl;
  cout<< **q;
  return 0;
}