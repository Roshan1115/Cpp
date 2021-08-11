// traverse by level but in alternate direcrtion in every direction

#include<iostream>
#include<stack>
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


void zigzagTraverse(Node *root){
  if(root == NULL){
    return;
  }
  stack<Node *> curLevel;
  stack<Node *> nextLevel;

  bool lefttoright = true;
  curLevel.push(root);

  while(!curLevel.empty()){
    Node *temp = curLevel.top();
    curLevel.pop();
    if(temp != NULL){
      cout<<temp->data<<" ";

      if(lefttoright){
        if(temp->left != NULL){
          nextLevel.push(temp->left);
        }
        if(temp->right != NULL){
          nextLevel.push(temp->right);
        }
      }
      // right to left
      else{
        if(temp->right != NULL){
          nextLevel.push(temp->right);
        }
        if(temp->left != NULL){
          nextLevel.push(temp->left);
        }
      }
    }

    if(curLevel.empty()){
      lefttoright = !lefttoright;
      curLevel.swap(nextLevel);
    }
  }
}

int main(){
  Node *root = new Node(10);
  insert(root, 5);
  insert(root, 15);
  insert(root, 2);
  insert(root, 6);
  insert(root, 12);
  insert(root, 17);

/*
       10
      /   \
     5    15
    / \   / \
   2   6 12  17

*/

  zigzagTraverse(root);
  cout<<endl;
  return 0;
}