#include<iostream>
#include<vector>
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


Node * buildBST(vector<int> v, int *idx, int key, int min, int max){
  if(*idx >= v.size()){
    return NULL;
  }
  Node * root = NULL;

  if(key > min && key < max){
    root = new Node(key);
    *idx += 1;

    if(*idx < v.size()){
      root->left = buildBST(v, idx, v[*idx], min, key);
    }
    if(*idx < v.size()){
      root->right = buildBST(v, idx, v[*idx], key, max);
    }
  }

  return root;
}

int main(){
  vector<int> v(6);
  for(int &i : v){
    cin>>i;
  }
  // 7 5 4 6 8 9

  int idx = 0;
  int rootelement = v[0];
  int min = INT_MIN;
  int max = INT_MAX;
  Node *root = buildBST(v, &idx, rootelement, min, max);


  cout<<"Binary search tree built.\n";
  inorder_traverse(root);
  cout<<endl;
  return 0;
}