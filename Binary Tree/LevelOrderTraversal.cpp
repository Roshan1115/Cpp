// given a binary tree. travere it with level order


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

void traverse_by_level(Node *root){
  if(root == NULL) return;

  queue< Node * > q;
  q.push(root);

  while( !q.empty() ){
    Node *cur = q.front();
    q.pop();
    
    cout<< cur->data<<" ";

    if(cur->left != NULL){
      q.push(cur->left);
    }
    if(cur->right != NULL){
      q.push(cur->right);
    }
  
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

  /*
            1
          /   \
        2       3
       / \     / \
      4   5   6   7

  */

  traverse_by_level(root);
  cout<<endl;

  return 0;
}