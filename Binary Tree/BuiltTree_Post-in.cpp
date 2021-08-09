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

int search(int arr[], int start, int end, int cur){
  for(int i=start; i<=end; i++){
    if(arr[i] == cur) return i;
  }
  return -1;
}

Node* build_post_in(int postorder[], int inorder[], int start, int end){
  static int n = 4;
  if(start > end){
    return NULL;
  }
  int cur = postorder[n];
  n--;
  Node *newNode = new Node(cur);
  if(start == end){
    return newNode;
  }
  int pos = search(inorder, start, end, cur);

  // we need to call for right subtree first
  newNode->right = build_post_in(postorder, inorder, pos+1, end);
  newNode->left = build_post_in(postorder, inorder, start, pos-1);

  return newNode;
}



void print_inorder(Node *node){
  if(node == NULL) return;

  print_inorder(node->left);
  cout<<node->data<<" ";
  print_inorder(node->right);
}

int main(){
  int postorder[] = {4,2,5,3,1};
  int inorder[] = {4,2,1,5,3};

  Node *root = build_post_in(postorder, inorder, 0, 4);

  print_inorder(root);
  return 0;
}