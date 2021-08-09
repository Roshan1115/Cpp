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

int height(Node *root){
  if(root == NULL) return 0;
  int lh = height(root->left);
  int rh = height(root->right);
  return max(lh, rh) + 1;
}


bool isBalanced(Node *root){
  if(root == NULL){
    return true;
  }

  int lh = 0, rh = 0;
  if(isBalanced(root->left) == false){
    return false;
  }
  if(isBalanced(root->right) == false){
    return false;
  }
  rh = height(root->right);
  lh = height(root->left);
  if(abs(lh - rh) <= 1){
    return true;
  }
  else{
    return false;
  }
}


bool isBalanced_optimised(Node *root, int *height){
  if(root == NULL){
    return true;
  }
  int lh = 0, rh = 0;
  if(isBalanced_optimised(root->left, &lh) == false){
    return false;
  }
  if(isBalanced_optimised(root->right, &rh) == false){
    return false;
  }
  *height = max(lh, rh) + 1;
  if(abs(lh - rh) <= 1){
    return true;
  }
  else{
    return false;
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


// uncomment these lines to see for unbalanced line
//  root->left->left->left = new Node(8);
//  root->left->left->left->left = new Node(9);



  /*
            1
          /   \
        2       3
       / \     / \
      4   5   6   7

 */

  if(isBalanced(root)){
    cout<<"Balandeced Tree.\n\n";
  }
  else cout<<"Inbalanced tree.\n\n";


  cout<<"By optimised searching.\n";
  int height = 0;
  if(isBalanced_optimised(root, &height)){
    cout<<"Balanced tree.\n";
  }
  else  cout<<"Inbalanced tree.\n";

  return 0;
}