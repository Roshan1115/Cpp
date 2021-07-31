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
 
void preorder_traverse(Node* root){

  if(root == NULL) return;

  cout<<root->data<<" ";
  preorder_traverse(root->left);
  preorder_traverse(root->right);

}

void inorder_traverse(Node* root){
  if(root == NULL) return;

  inorder_traverse(root->left);
  cout<<root->data<<" ";
  inorder_traverse(root->right);

}

void postorder_traverse(Node* root){
  if(root == NULL) return;

  postorder_traverse(root->left);
  postorder_traverse(root->right);
  cout<<root->data<<" ";
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

  preorder_traverse(root);
  cout<<endl;

  inorder_traverse(root);
  cout<<endl;
 
  postorder_traverse(root);
  cout<<endl;



  return 0;
}