// count all the nodes of a binary tree


// need to check for wrong ans

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


int countNodes(Node *root){
  if(root == NULL){
    return 0;
  }

  return (1 + countNodes(root->left) + countNodes(root->right));
}

int sumNode(Node* root){
  if(root == NULL){
    return 0;
  }

  return sumNode(root->left) + sumNode(root->right) + root->data;
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

  cout<< countNodes(root)<<endl;

  cout<< sumNode(root)<<endl;
  return 0;
}