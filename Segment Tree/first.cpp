/*
In segment tree
querry is in O(log n)
update is also in O(log n)

it works as devide and conquore rule in an array.
*/

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

const int N = 1e5+2;
int a[N], tree[4*N];

void build(int node, int start, int end){
  if(start == end){
    tree[node] = a[start];  return;
  }
  int mid = (start+end)/2;
  build(2*node, start, mid);
  build(2*node+1, mid+1, end);

  tree[node] = tree[2*node] + tree[2*node+1];
}

int main(){
  int n; cin >> n;
  rep(i,0,n)
  cin>> a[i];

  build(1,0,n-1);

  rep(i,1,15)
    cout<<tree[i]<<" "; endline;
  return 0;
}

// use : g++ -std=c++11 


/*
input 
8
5 3 2 4 1 8 6 10

output : 39 14 25 8 6 9 16 5 3 2 4 1 8 6
*/