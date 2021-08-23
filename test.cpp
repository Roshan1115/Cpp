#include<iostream>
#include<vector>
using namespace std;

int main(){
  vector<int> v(3);

  for(int i=0; i<3; i++){
    v.push_back(i*10);
  }
  cout<< v.back()<< endl;
  return 0;
}