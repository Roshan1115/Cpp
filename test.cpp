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
  vi a(4);
  a.push_back(23);

  for(int x : a)
    cout<< x<<" ";
  cout<< endl;
  return 0;
}

// use : g++ -std=c++11 