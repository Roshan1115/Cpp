// given number n which represent number of nodes. construct all possible binary trees from that node and print the preorder sequencial.

#include<iostream>
#include<vector>
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

void preorder_print(Node *root){
  if(root == NULL){
    return;
  }
  cout<<root->data<<" ";
  preorder_print(root->left);
  preorder_print(root->right);
}

vector<Node *> constructTree(int start, int end){
  vector<Node *> trees;
  if(start > end){
    trees.push_back(NULL);
    return trees;
  }
  for(int i=start; i<=end; i++){
    vector<Node *> lefttree = constructTree(start, i-1);
    vector<Node *> righttree = constructTree(i+1, end);

    for(int j=0; j<lefttree.size(); j++){
      Node *left = lefttree[j];
      for(int k=0; k<righttree.size(); k++){
        Node *right = righttree[k];
        Node *node = new Node(i);
        node->left = left;
        node->right = right;
        trees.push_back(node);
      }
    }
  }
  return trees;
}

int main(){
  vector<Node*> totaltrees = constructTree(1, 3);

  // print all the binary trees
  for(Node * i : totaltrees){
    preorder_print(i);
    cout<<endl;
  }
  return 0;
}