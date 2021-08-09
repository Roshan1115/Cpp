
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

void inorder_traverse(Node* root){
  if(root == NULL) return;

  inorder_traverse(root->left);
  cout<<root->data<<" ";
  inorder_traverse(root->right);

}


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

int main(){
  Node *firstBST = new Node(5);
  insert(firstBST, 1);
  insert(firstBST, 3);
  insert(firstBST, 4);
  insert(firstBST, 2);
  insert(firstBST, 7);

/*
        5
       / \
      1   7
       \
        3
       / \
      2   4

*/

  inorder_traverse(firstBST);;
  return 0;
}