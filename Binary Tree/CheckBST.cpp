// given a bt. check it is a valid bst or not

#include<iostream>
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

Node * insert(Node *root, int val){
  if(root == NULL){
    return new Node(val);
  }
  if(val < root->data){
    root->left = insert(root->left,val);
  }
  else {
    root->right = insert(root->right, val);
  }
  return root;
}


bool checkBST(Node *root){
  if(root == NULL){
    return true;
  }
  if(root->left != NULL && root->left->data > root->data){
    return false;
  }
  if(root->right != NULL && root->right->data < root->data){
    return false;
  }
  bool letfcheck = checkBST(root->left);
  bool rightcheck = checkBST(root->right);

  return (letfcheck && rightcheck);
}

int main(){
  Node *root = new Node(5);
  insert(root, 1);
  insert(root, 3);
  insert(root, 4);
  insert(root, 2);
  insert(root, 7);

/*
        5
       / \
      1   7
       \
        3
       / \
      2   4

*/

  if(checkBST(root)){
    cout<< "it is a binary tree.\n";
  }
  else{
    cout<<"Not a binary tree.\n";
  }
  return 0;
}