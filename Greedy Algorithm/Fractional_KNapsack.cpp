// put n items of given weight and value in a knapsack of capacity w
// to get the maximum total value in the knapsack

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
  int n,w; cin >> n >> w;
  vii a(n);

  // we have greater<int> to make out map in decreasing order
  map<int, pii, greater<int> > valuePerWeight;

  rep(i,0,n){
    pii p;
    // first is weight ans second is value
    cin >> p.first >> p.second;

    int vpw = p.second/p.first;
    valuePerWeight[vpw] = p;
  }

  int value = 0;
  map<int, pii>:: iterator it;
  for(it = valuePerWeight.begin(); it!= valuePerWeight.end(); it++){

    if(it->second.first <= w){
      value += it->second.second;
      w -= it->second.first;
    }else{
      value += w * it->first;
      w = 0;
      break;
    }

  }

  cout<< value<< endl;
  return 0;
}

// use : g++ -std=c++11 

/*
input : 
5
20
7 21
4 24
6 12
5 40
6 30

output : 109
*/