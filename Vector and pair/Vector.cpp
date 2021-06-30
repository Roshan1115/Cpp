#include<iostream>
#include<vector>
using namespace std;

int main(){
  vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);

  // to print 

  for(int i=0; i<v.size(); i++){
    cout<< v[i]<< " ";
  }
  cout<<endl;   // 1 2 3

  vector<int>::iterator i;    // here i is a pointer
  for(i=v.begin(); i != v.end(); i++){
    cout<< *i << " ";
  }
  cout<< endl;    // 1 2 3

  for(int i : v){    // here i is the element of vector
    cout<< i<< " ";
  }
  cout<< endl;  // 1 2 3

  // to delete last element in a vector
  v.pop_back(); 

  for(int i:v){
    cout<< i<< " ";
  }
  cout<< endl;    // 1 2

  // sorting
  vector<int> v2;  // 3 is size
  v2.push_back(34);
  v2.push_back(21);
  v2.push_back(56);

  sort(v2.begin(), v2.end());
  
  for(int i : v2){
    cout<< i<<" ";
  }
  cout<<endl;

  // swaping
  swap(v, v2);

  cout<<"V is now ";
  for(int i : v){
    cout<< i<<" ";
  }
  cout<<endl;

  cout<<"V2 is now ";
  for(int i : v2){
    cout<< i<<" ";
  }
  cout<<endl;
  return 0;
}