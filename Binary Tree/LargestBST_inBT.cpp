// given a bt. return the largest possible size of a bst that the given bt can have.

#include<iostream>
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


// helper function
bool isBST(Node *root){
  if(root == NULL) return true;
  if(root->left != NULL && root->left->data > root->data){
    return false;
  }
  if(root->right != NULL && root->right->data < root->data){
    return false;
  }
  bool lcheck = isBST(root->left);
  bool rcheck = isBST(root->right);

  return (lcheck && rcheck);
}

int countBST(Node *root){
  if(root == NULL){
    return 0;
  }
  return(1 + countBST(root->left) + countBST(root->right));
}

// helper structure
struct info{
  int size;
  int max; 
  int min;
  int ans;
  bool isBST;
};


// the actual function
info largestBST(Node *root){
  if(root == NULL){
    info temp;
    temp.size = 0;
    temp.max = INT_MIN;
    temp.min = INT_MAX;
    temp.ans = 0;
    temp.isBST = true;

    return temp;
  }
  if(root->left == NULL && root->right == NULL){
    info temp;
    temp.size = 1;
    temp.max = root->data;
    temp.min = root->data;
    temp.ans = 1;
    temp.isBST = true;
    
    return temp;
  }

  info leftinfo = largestBST(root->left);
  info rightinfo = largestBST(root->right);

  info cur;
  cur.size = 1 + leftinfo.size + rightinfo.size;

  if(leftinfo.isBST && rightinfo.isBST && leftinfo.max < root->data && rightinfo.min > root->data){
    cur.max = max(root->data, max(leftinfo.max, rightinfo.max));
    cur.min = min(root->data, min(leftinfo.min, rightinfo.min));
    cur.ans = cur.size;
    cur.isBST = true;

    return cur;
  }

  cur.ans = max(leftinfo.ans, rightinfo.ans);
  cur.isBST = false;
  return cur;

}

int main(){
  Node *root = new Node(10);
  insert(root, 5);
  insert(root, 15);
  insert(root, 2);
  insert(root, 6);
  insert(root, 12);
  insert(root, 17);

  insert(root, 20);
/*
        10
       /   \
      5    15
     / \   / \
    2   6 12  17
                \
                 20

*/


  // for experiment
  Node *newroot = new Node(15);
  newroot->left = new Node(20);
  newroot->right = new Node(30);
  newroot->left->left = new Node(5);
  
  // cout<< largestBST(root)<<endl;
  // cout<<largestBST(newroot)<<endl;

  // inorder_traverse(newroot);
  // cout<<endl;

  info answer0 = largestBST(root);
  cout<< answer0.ans<<endl;

  info answer = largestBST(newroot);
  cout<< answer.ans<<endl;

  return 0;
}