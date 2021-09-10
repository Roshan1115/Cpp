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
  int n = 4;
  vi v;

  rep(i,0,n)
    cin >> v[i];

  v.pop_back();
  cout<< v.size() << endl;
  // v.pop_back();

  while(!v.empty()){
    cout<< v.back()<<" ";
    v.pop_back();
  }
  return 0;
}

// use : g++ -std=c++11 