#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<algorithm>
#include<set>
#include<limits>
using namespace std;

#define endline cout<<endl
#define vi vector<int>
#define vii vector<pair<int, int> >
#define pii pair<int, int>
#define rep(i,a,b) for(int i=a; i<b; i++)

int main(){
  string s = "na";
  string t = "apna collegena";
  int S = s.size(), T = t.size();

  for(int i=0; i<T-S+1 ; i++) {
    if(t.substr(i, S) == s){
      cout<<"Found at index "<< i; endline;
    }
  }

  return 0;
}

// use : g++ -std=c++11 