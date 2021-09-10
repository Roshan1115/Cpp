#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

#define vi vector<int>
#define vii vector<pair<int, int> >
#define pii pair<int, int>
#define rep(i,a,b) for(int i=a; i<b; i++)


void forEach(vi &v, void(* lam)(int) ){
  rep(i,0,v.size()){
    lam(v[i]);
  }
}

void fun(int n){
  cout<< n<< endl;
}

int main(){

  // cout<< v.begin() << endl;

  vi v = {1,2,3,4,5,6,7};
  int a= 444;

  vi :: iterator it;
  for(it = v.begin(); it != v.end(); it++)
    cout<< *it <<" ";
  cout<< endl;

  forEach(v, fun);
  cout<< endl;
  
  return 0;
}

// use : g++ -std=c++11 