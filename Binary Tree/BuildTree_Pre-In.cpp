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

Node* build_pre_in(int preorder[], int inorder[], int start, int end){
  static int idx = 0;
  if(start > end){
    return NULL; 
  }
  int cur = preorder[idx];
  idx++;
  Node *n = new Node(cur);
  if(start == end){
    return n;
  }
  int pos = search(inorder, start, end, cur);

  n->left = build_pre_in(preorder, inorder, start, pos-1);
  n->right = build_pre_in(preorder, inorder, pos+1, end);

  return n;
}

void print_inorder(Node *node){
  if(node == NULL) return;
  print_inorder(node->left);
  cout<<node->data<<" ";
  print_inorder(node->right);
}

int main(){
  
  int preorder[] = {1,2,4,3,5};
  int inorder[] = {4,2,1,5,3};

  Node *root = build_pre_in(preorder, inorder, 0, 4);

  print_inorder(root);
  return 0;
}