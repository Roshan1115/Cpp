#include<iostream>
#include<vector>
using namespace std;

vector< vector<int> > ans;

void permute(vector<int> &a, int idx){
  if(idx == a.size()){
    ans.push_back(a);
    return;
  }

  for(int i= idx; i< a.size(); i++){
    swap(a[i], a[idx]);
    permute(a, idx+1);
    swap(a[i], a[idx]);
  }
  return;
}

int main(){
  int n;
  cin>>n;
  vector<int> v(n);

  for(int &i : v)
    cin>> i;

  cout<<endl;
  permute(v, 0);
  cout<<endl;

  for(auto v : ans){
    for(int i : v){
      cout<< i<< " ";
    }
    cout<< endl;
  }
  return 0;
}