// multiset can contain duplicate
// elements are in sorted order
// acess of i'th element randomly is not possbile in O(1) or O(log n) time
// included in <set> header file
// multiset is defined using balancced bst
// insertion = O(log n)
// Deletion = O(log n)
// lower / upper_bound = O(log n)

#include<iostream>
#include<set>
using namespace std;

int main(){
  multiset<int> ms;
  ms.insert(1);
  ms.insert(4);
  ms.insert(5);
  ms.insert(2);
  ms.insert(2);
  ms.insert(2);
  ms.insert(2);
  ms.insert(10);
  ms.insert(10);
  ms.insert(10);
  ms.insert(10);
  ms.insert(10);

  for(auto i : ms){
    cout<< i<<" ";
  }cout<< endl;

  cout<<"Erasing all 2s : ";
  ms.erase(2);

  for(auto i : ms){
    cout<< i<<" ";
  }cout<< endl;


  cout<<"Erasing only one 10  : ";
  ms.erase(ms.find(10));
  for(auto i : ms){
    cout<< i<<" ";
  }cout<< endl;

  return 0;
}