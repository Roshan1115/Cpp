#include<iostream>
#include<queue>
using namespace std;

struct Node{
  int data;
  Node* left;
  Node* right;

  Node(int val){
    data = val;
    left = NULL;
    right = NULL;
  }
};

void rightView(Node* root){
  queue<Node *> q;
  q.push(root);
  q.push(NULL);
  Node *f = root;

  while(!q.empty()){
    Node *fnode = q.front();
    q.pop();
    if(fnode != NULL){
      if(fnode->left) q.push(fnode->left);
      if(fnode->right) q.push(fnode->right);
    }
    else if(!q.empty()){
      q.push(NULL);
      cout<< f->data <<" ";
    }
    else if(q.empty()){
      cout<< f->data<<" ";
    }
    f = fnode;
  }
}

void leftView(Node* root){
  queue<Node *> q;
  q.push(root);
  q.push(NULL);
  Node *f = root;

  while(!q.empty()){
    Node *fnode = q.front();
    q.pop();
    if(fnode != NULL){
      if(fnode->right) q.push(fnode->right);
      if(fnode->left) q.push(fnode->left);
    }
    else if(!q.empty()){
      q.push(NULL);
      cout<< f->data <<" ";
    }
    else if(q.empty()){
      cout<< f->data<<" ";
    }
    f = fnode;
  }
}


int main(){
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  root->right->right = new Node(7);


// uncomment these lines to add two nodes to the left of tree
 root->left->left->left = new Node(8);
 root->left->left->left->left = new Node(9);


  /*
            1
          /   \
        2       3
       / \     / \
      4   5   6   7
     /
    8
   /
  9

 */

  cout<<"Right view : "; 
  rightView(root);
  cout<<endl;

  cout<<"Left view : "; 
  leftView(root);
  cout<<endl;
  
  return 0;
}