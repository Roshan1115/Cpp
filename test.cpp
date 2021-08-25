#include<iostream>
#include<vector>
using namespace std;

int main(){
  vector<int> v(3);

  for(auto &i : v)
    cin>> i;

  for(auto &i : v)
    cout<<  i;
  cout<< endl;
  

  return 0;
}