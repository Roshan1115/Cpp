// flatten a bt to its pre order traversal


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

// first case
void printSubtrees(Node *root, int k){
  if(root == NULL || k<0){
    return;
  }
  if(k==0){
    cout<<root->data<<" ";
    return;
  }
  printSubtrees(root->left, k-1);
  printSubtrees(root->right, k-1);
}

// second case
int printnodeAt_k(Node *root, Node *target, int k){
  if(root == NULL){
    return -1;
  }
  if(root == target){
    printSubtrees(root, k);
    return 0;
  }
  int dl = printnodeAt_k(root->left, target, k);
  if(dl != -1){
    if(dl +1 == k){
      cout<<root->data<<" ";
    }else{
      printSubtrees(root->right, k-dl - 2);
    }
    return 1+dl;
  }

  int dr = printnodeAt_k(root->right, target, k);
  if(dr != -1){
    if(dr +1 == k){
      cout<<root->data<<" ";
    }else{
      printSubtrees(root->left, k-dr - 2);
    }
    return 1+dr;
  }

  return -1;
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

  Node *target =  root->left->right;    // 5
  printnodeAt_k(root, target, 3);
  
  return 0;
}