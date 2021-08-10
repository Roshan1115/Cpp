

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

void inorder_traverse(Node* root){
  if(root == NULL) return;

  inorder_traverse(root->left);
  cout<<root->data<<" ";
  inorder_traverse(root->right);

}


Node* buildBST(int *arr, int start, int end){

  if(start <= end){
    int mid = (start + end) / 2;
    int cur = arr[mid];
    Node *root = new Node(cur);

    root->left = buildBST(arr, start, mid-1);
    root->right = buildBST(arr, mid+1, end);
    
    return root;
  }
  return NULL;
}

int main(){
  int arr[] = {10, 20, 30, 40, 50};
  Node *root = buildBST(arr, 0, 4);

  // cout<<root->data<<endl;
  cout<<"Binary search tree build.\n";
  inorder_traverse(root);
  cout<<endl;
  return 0;
}