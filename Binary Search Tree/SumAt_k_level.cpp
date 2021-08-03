/*
find the sum of all node in k level.
logic : use queue to traverse by levels and keep count of level. if count -- level then add to sum.
*/

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

int sumAt_k(Node* root, int k){
  if(root == NULL) return -1;

  queue<Node*> q;
  q.push(root);
  q.push(NULL);
  int sum = 0, level = 0;

  while(!q.empty()){
    Node* node = q.front();
    q.pop();

    if(node != NULL){
      if(level == k){
        sum += node->data;
      }
      if(node->left){
        q.push(node->left);
      }
      if(node->right){
        q.push(node->right);
      }
    }
    else if(!q.empty()){
      q.push(NULL);
      level++;
    }
  }

  return sum;
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

  cout<< sumAt_k(root, 2)<<endl;
  return 0;
}