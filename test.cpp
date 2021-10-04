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

int main(){
  vector< vi > v;

  rep(i,0,4) {
    v.push_back({i, i+10, i+20});
  }

  for(auto i : v){
    for(auto j : i){
      cout<< j <<" ";
    }
    cout<< endl;
  }
  return 0;
}

// use : g++ -std=c++11 