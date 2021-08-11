
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

bool isIdentical(Node *root1, Node *root2){
  if(root1 == NULL && root2 == NULL){
    return true;
  }
  if(root1 == NULL){
    return false;
  }
  if(root2 == NULL){
    return false;
  }
  if(root1->data != root2->data){
    return false;
  }
  bool lcheck = isIdentical(root1->left, root2->left);
  bool rcheck = isIdentical(root1->right, root2->right);

  return(lcheck && rcheck);
}

int main(){
  Node *root = new Node(10);
  insert(root, 5);
  insert(root, 15);
  insert(root, 2);
  insert(root, 6);
  insert(root, 12);
  insert(root, 17);

/*
       10
      /   \
     5    15
    / \   / \
   2   6 12  17

*/

  Node * root2 = new Node(10);
  insert(root2, 5);
  insert(root2, 17);

  if(isIdentical(root, root2)){
    cout<<"Identical tree.\n";
  }
  else cout<<"Not identical.\n";
  return 0;
}