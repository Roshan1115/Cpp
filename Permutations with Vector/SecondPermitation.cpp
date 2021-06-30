#include<iostream>
#include<vector>
using namespace std;

vector< vector<int> > ans;

int main(){
  int n;
  cin>>n;
  vector<int> v(n);

  for(int &i : v)
    cin>> i;

  sort(v.begin(), v.end());
  do{
    ans.push_back(v);
  }while(next_permutation(v.begin(), v.end()));

  for(auto v : ans){
    for(int i : v){
      cout<< i<< " ";
    }
    cout<< endl;
  }
  return 0;
}