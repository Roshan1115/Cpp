// unordered set contains unique elements
// acess of i'th element randomly is not possbile in O(1) or O(log n) time
// element are not in sorted order.
// included in <unordered_set> header file
// set is defined using hashing
// inserton/deletion are in O(1) in avg case and O(n) in worst case.

#include<iostream>
#include<unordered_set>
using namespace std;

int main(){
  unordered_set<int> us;
  us.insert(1);
  us.insert(3);
  us.insert(2);
  us.insert(5);

  for(auto i : us){
    cout<< i<< " ";
  }
  cout<< endl;

  us.erase(2);
  us.erase(us.begin());

  for(auto i : us){
    cout<< i<< " ";
  }
  cout<< endl;


  return 0;
}