/*
Maxheap are generalised using binary tree and impleated using an array or vector.
the root node is bigger than the child node.
left child = 2p where p is parent node
right child = 2p + 1 where p is parent node.
We generally store the data from the index number 1, the zeroth index in the vecrtor have a garbage value
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class MaxHeap{
  private:
  int size = 0;
  vector<int> vect = {-1};
  
  int parent(int index){
    return index >> 1;  // same ae index/2
  }
  int leftchild(int index){
    return index << 1; // same as index * 2
  }
  int rightchild(int index){
    return (index << 1) + 1;   // index * 2 + 1
  }

  public:
  MaxHeap(){
    vect.push_back(0);
  }
  bool isEmpty(){ return size == 0; }
  int getMax(){ return vect[1]; }
  void insert(int val);
  void shiftup(int index);
  void shiftdown(int index);
  void delete_max();
};


void MaxHeap :: shiftup(int index){
  if(index == 1 || index > size) return;

  int pi = parent(index);
  if(vect[index] > vect[pi]){
    swap(vect[index], vect[pi]);
  }
  shiftup(pi);
}

void MaxHeap :: shiftdown(int index){
  if(index > size) return;

  int sizeId = index;
  if(leftchild(index) <= size && vect[index] < vect[leftchild(index)]){
    sizeId = leftchild(index);
  }
  if(rightchild(index) <= size && vect[sizeId] < vect[rightchild(index)]){
    sizeId = rightchild(index);
  }

  if(sizeId != index){
    swap(vect[index], vect[sizeId]);
    shiftdown(sizeId);
  }
}

void MaxHeap :: insert(int val){
  vect[++size] = val;
  shiftup(size);

}

void MaxHeap :: delete_max(){
  if(size< 1) return;
  if(size == 1){
    size--;
    return;
  }
  swap(vect[1], vect[size--]);
  shiftdown(1);
}

int main(){
  MaxHeap *PriorityQueue = new MaxHeap();
  if(PriorityQueue->isEmpty()){
    cout<<"It is empty.\n";
  }
  else{
    cout<<"It is not empty.\n";
  }
  PriorityQueue->insert(10);
  PriorityQueue->insert(33);
  PriorityQueue->insert(80);
  PriorityQueue->insert(40);
  PriorityQueue->insert(20);

  // PriorityQueue->displayall();
  cout<<"Max element "<<PriorityQueue->getMax()<<endl;

  PriorityQueue->delete_max();

  cout<<"After deleting, the new max is "<< PriorityQueue->getMax()<<endl;

  if(PriorityQueue->isEmpty()){
    cout<<"It is empty.\n";
  }
  else{
    cout<<"It is not empty.\n";
  }
  return 0;
}