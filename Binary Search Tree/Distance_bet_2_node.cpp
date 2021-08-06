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

// LCA  = lowest common ancestor
Node *  LCA(Node *root, int  n1, int n2){
  if(root == NULL) return NULL;

  if(root->data == n1 || root->data == n2){
    return root;
  }
  Node *left = LCA(root->left,  n1, n2);
  Node *right = LCA(root->right,  n1, n2);

  if(left != NULL && right  != NULL){
    return root;
  }
  else if(left == NULL && right == NULL){
    return NULL;
  }
  else if(left != NULL){
    return LCA(root->left, n1, n2);
  }
  else{
    return LCA(root->right, n1, n2);
  }
}

// the function to compute the root to a given node
int distance(Node *root,  int n){
  if(root == NULL) return -1;
  if(root->data == n) return 0;

  int l = distance(root->left, n);
  int r = distance(root->right, n);

  if(l == -1 && r == -1) return -1;

  else if(l==-1){
    return r+1;
  }
  else{
    return l+1;
  }
}

// the actual function to compute distance between two nodes.
int distance_between(Node *root, int n1,  int n2){
  Node *ancestor = LCA(root, n1, n2);
  if(ancestor == NULL){
    return 0;
  }
  
  int d1 = distance(ancestor, n1);
  int d2 = distance(ancestor, n2);

  return d1+d2;
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


  cout<< distance_between(root, 8, 6)<< endl;
  return 0;
}