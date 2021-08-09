// LCA is lowest common ancester

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

Node * LCA(Node *root, int n1, int n2){
  if(root == NULL) {
    return NULL;
  }
  if(root->data == n1 || root->data == n2){
    return root;
  }
  Node *left  = LCA(root->left, n1, n2);
  Node *right  = LCA(root->right, n1, n2);

  if(left != NULL && right != NULL){
    return root;
  }
  else if(left == NULL && right != NULL){
    return LCA(root->right, n1, n2);
  }
  else if(left != NULL && right == NULL){
    return LCA(root->left, n1, n2);
  }
  else{
    return NULL;
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
         2      3
       / \     / \
      4   5   6   7
     /
    8
   /
  9
  
 */

  cout<< LCA(root, 5, 6)->data <<endl;
  
  return 0;
}