/*
given an integer n, then n activities will be given with start time and end time. output the maximum number of activities that a persion can do if he/she can do one work at a time.
*/

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
  int n; cin >> n;
  vector< vi > v(n);

  rep(i,0,n){
    int start, end;
    cin>> start >> end;

    v[i].push_back(start);
    v[i].push_back(end);
  }

  // sorting using lamda comparator function 
  sort(v.begin(), v.end(), [&](vi &a, vi &b){
    return a[1] <= b[1];
  });

  int take = 1;
  int end = v[0][1];

  rep(i,1,n){
    if(v[i][0] >= end){
      take++;
      end = v[i][0];
    }
  }

  cout<< take<< endl;

  return 0;
}

/*
input : 
3
10 20
12 15
20 30

output : 2
*/