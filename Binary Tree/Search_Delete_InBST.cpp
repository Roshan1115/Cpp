// searching in bst requires O(log n) time

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


Node * search(Node *root, int key){
  if(!root){
    return  NULL;
  }
  if(root->data == key){
    return root;
  }
  else if(key < root->data){
    return search(root->left, key);
  }
  return search(root->right, key);
}



// inorder successor is the next element which comes after a given element.
Node * inorderSuccessor(Node *root){
  Node *cur = root;
  while(cur->left != NULL){
    cur = cur->left;
  }
  return cur;
}
Node* deleteNode(Node *root, int key){

  if(key < root->data){
    root->left = deleteNode(root->left, key);
  }
  else if(key > root->data){
    root->right =  deleteNode(root->right, key);
  }

  else{
      //case 1
      if(root->left == NULL){
        Node *temp = root->right;
        free(root);
        return temp;
      }
      // case 2
      else if(root->right == NULL){
        Node *temp = root->left;
        free(root);
        return temp;
      }
      // case 3
      Node *temp = inorderSuccessor(root->right);
      root->data = temp->data;
      root->right = deleteNode(root->right, temp->data);
  }
  return root;
}

int main(){
  Node *root = new Node(5);
  insert(root, 1);
  insert(root, 3);
  insert(root, 4);
  insert(root, 2);
  insert(root, 7);

/*
        5
       / \
      1   7
       \
        3
       / \
      2   4

*/

  // searching
  Node *result = search(root, 3);
  if(result){
    cout<<"Found at address : "<<result<<" and value is "<<result->data<<endl;
  }
  else{
    cout<<"Not found.\n";
  }


  // deleting
  cout<<"\nInorder traverse before deleting.\n";
  inorder_traverse(root);
  cout<<endl;

  Node* newRoot = deleteNode(root, 3);

  cout<<"\nInorder traverse after deleting.\n";
  inorder_traverse(newRoot);
  cout<<endl;

  return 0;
}


/*
output : 
Found at address : 0x7fc425c05a60 and value is 3

Inorder traverse before deleting.
1 2 3 4 5 7 

Inorder traverse after deleting.
1 2 4 5 7 
*/