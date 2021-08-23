#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  vector<int> v1 = {10,23,45,2};
  make_heap(v1.begin(), v1.end());
  cout<< v1.front()<<endl;
  return 0;
}