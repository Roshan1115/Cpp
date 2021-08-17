// set contains unique elements
// element are in sorted order
// acess of i'th element randomly is not possbile in O(1) or O(log n) time
// included in <set> header file
// set is defined using balancced bst

#include<iostream>
#include<set>
using namespace std;

int main(){
  set<int> s;
  s.insert(1);
  s.insert(5);
  s.insert(10);
  s.insert(2);
  s.insert(2);
  s.insert(3);
  s.insert(4);

  for(int i: s){
    cout<<i<<" ";
  }cout<<endl;

  for(auto i= s.rbegin(); i != s.rend(); i++){
    cout<< *i<<" ";
  }cout<<endl;

  s.erase(2);
  s.erase(s.begin());

  for(int i: s){
    cout<<i<<" ";
  }cout<<endl;
  return 0;
}