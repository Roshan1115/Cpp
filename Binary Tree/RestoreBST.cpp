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

void calculatePointers(Node *root, Node **first, Node **mid, Node **last, Node **prev){
  if(root == NULL) return;

  

  calculatePointers(root->left, first, mid, last, prev);

  // cout<<root->data<<endl;
  if(*prev != NULL && root->data < (*prev)->data){
    if(*first != NULL){
      *last = root;
    }
    else{
      *first = *prev;
      *mid = root;
    }
  }
  *prev = root;

  calculatePointers(root->right, first, mid, last, prev);
}

void swap(int *first, int *second){
  int temp = *first;
  *first = *second;
  *second = temp;
}

void restoreBST(Node *root){
  Node *first, *mid, *last, *prev;
  first = NULL;
  mid = NULL;
  last = NULL;
  prev = NULL;

  calculatePointers(root, &first, &mid, &last, &prev);

  // caase 1
  if(first && last){
    swap(&(first->data), &(last->data));
  }
  //  case 2
  else if(first && mid){
    swap(&(first->data), &(mid->data));
  }
}

int main(){
  Node *root = new Node(10);
  root->left = new Node(15);
  root->right = new Node(5);
  root->left->left = new Node(2);
  root->left->right = new Node(6);
  root->right->left = new Node(12);
  root->right->right = new Node(17);


  /*
       10
      /   \
     15    5
    / \   / \
   2   6 12  17

*/


  inorder_traverse(root); cout<< endl;

  restoreBST(root);

  inorder_traverse(root); cout<< endl;
  return 0;
}