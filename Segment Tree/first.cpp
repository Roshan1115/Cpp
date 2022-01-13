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


// l to r is the range
int querry(int node, int start, int end, int l, int r) {
  if(start > r || end < l) {
    return 0;
  }
  else if(start >= l && end <= r) {
    return tree[node];
  }
  
  int mid = (start + end)/2;

  int q1 = querry(2*node, start, mid, l, r);
  int q2 = querry(2*node+1, mid+1, end, l,r);

  return q1 + q2;
}



int main(){
  int n; cin >> n;
  rep(i,0,n)
  cin>> a[i];

  build(1,0,n-1);

  rep(i,1,15)
    cout<<tree[i]<<" "; endline;

  while(1){
    int type;
    cout<<"Enter type. 1 for querry, -1 for exiting.\n";
    cin>>type;
    if(type == -1)
      break;
    if(type == 1){
      int l,r;
      cout<<"Enter range. 2 digits spaced less then "<<n<<endl;
      cin>> l >> r;
      int ans = querry(1, 0, n-1, l, r);
      cout<< ans<<endl;
    }
  }
  return 0;
}

// use : g++ -std=c++11 


/*
input 
8
5 3 2 4 1 8 6 10
1
1 5
-1


output

39 14 25 8 6 9 16 5 3 2 4 1 8 6 
Enter type. 1 for querry, -1 for exiting.
Enter range. 2 digits spaced less then 8
18
Enter type. 1 for querry, -1 for exiting.
*/