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

//   while( head != NULL){
//     cout<<head->data<<" -> ";
//     head = head->next;
//   }
//   cout<<"NULL";
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

//   node *first = new node(0);
//   for(int i=1; i<10; i++){
//     insert(first, i);
//   }
//   display(first);
//   display(first);
//   return 0;
// }













// #include<iostream>
// using namespace std;

// class node{
//   public:
//   int data;
//   node *next;
//   node(int vale){
//     data = vale;
//   }
//   void display(){
//     cout<<data<<endl;
//   }
// };

// void display(node *head){

//   node *temp = head;
//   while( temp != NULL){
//     cout<<temp->data<<" -> ";
//     temp = temp->next;
//   }
//   cout<<"NULL";
//   cout<<endl;
// }

// void change(node * b){
//   b->data = 100;
// }

// int main(){
//   node *a = new node(12);
//   node *b = new node(13);
//   node *c = new node(14);

//   a->next = b;
//   b->next = c;
//   c->next = NULL;

//   // change(a);
//   display(a);
//   display(a);
//   return 0;
// }