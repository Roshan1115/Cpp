// find the sum of node of all path and return the maximum of a path.

#include<iostream>
#include<queue>
#include<limits.h>
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

int maxSum_utility(Node *root, int &ans){
  if(root ==NULL){
    return 0;
  }
  int left = maxSum_utility(root->left, ans);
  int right = maxSum_utility(root->right, ans);

  int nodeMax = max(max(root->data, root->data + left + right), max(root->data + left, root->data + right));

  ans =  max(ans, nodeMax);

  int singlePathsum = max(root->data, max(root->data + left, root->data + right));
  return singlePathsum;;
}

int max_sum(Node *root){
  if(root == NULL){
    return 0;
  }
  int ans = INT_MIN;
  maxSum_utility(root, ans);
  return ans;
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
 root->left->left->left->left = new Node(-34);


  /*
            1
          /   \
         2      3
       / \     / \
      4   5   6   7
     /
    8
   /
 -34
  
 */

  cout<< max_sum(root) << endl;
  
  return 0;
}