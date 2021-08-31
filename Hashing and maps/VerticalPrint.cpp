/*
Given a BT, print all the elements that will be visible if you see the tree from top
*/

#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define rep(i,a,b) for(int i=a; i<b; i++)

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


void getVerticalOrder(Node *root, map<int, vi> &m, int i){
  if(root == NULL)
    return;

  m[i].push_back(root->data);

  getVerticalOrder(root->left, m, i-1);
  getVerticalOrder(root->right, m, i+1);
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

  map<int, vi> m;
  int i= 0;
  getVerticalOrder(root, m, i);

  for(auto it = m.begin(); it != m.end(); it ++){
    for(auto &i : it->second){
      cout<<i<<" ";
    }cout<< endl;
  }
  cout<< endl;

  return 0;
}

/*
4 
2 
1 5 6 
3 
7 
*/