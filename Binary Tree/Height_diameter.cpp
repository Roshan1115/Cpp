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


int height(Node* root){
  if(root == NULL) return 0;
  return(1 + max(height(root->left), height(root->right)));
}


int diameter_not_optimised(Node *root){
  if(root == NULL) return 0;

  int lheight = height(root->left);
  int rheight = height(root->right);
  int curDiameter = lheight + rheight + 1;

  int lDiameter = diameter_not_optimised(root->left);
  int rDiameter = diameter_not_optimised(root->right);

  return max(curDiameter, max(lDiameter, rDiameter));
} // o(n^2) time


int diameter_optimised(Node *root, int *height){
  if(root == NULL){
    *height = 0;
    return 0;
  }
  int lh = 0, rh = 0;
  int ldia = diameter_optimised(root->left, &lh);
  int rdia = diameter_optimised(root->right, &rh);

  int curDia = lh + rh + 1;
  *height = max(lh,rh) + 1;

  return max(curDia, max(ldia, rdia));
 
} // O (n) time

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

  cout<<"Height : "<< height(root)<<endl;

  cout<<"Diameter : "<< diameter_not_optimised(root)<< endl;

  int height = 0;
  cout<<"Diameter : "<< diameter_optimised(root, &height)<< endl;


  return 0;
}