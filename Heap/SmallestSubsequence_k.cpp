/*
Gien an array and integer k, fint the length of smallest subsequence whose sum >= k.
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define rep(i,a,b) for(int i=a; i<b; i++)

int main(){
  int n,k; cin>> n >> k;
  vi a(n);

  rep(i,0,n)
    cin>> a[i];
  
  // max heap
  priority_queue<int, vi> pq;

  rep(i, 0, n)
    pq.push(a[i]);
  
  int sum = 0, count  = 0;

  while(!pq.empty()){
    sum += pq.top();
    pq.pop();
    count++;
    if(sum >= k){
      break;
    }
  }
  if(sum < k){
    cout<< "subsequence not present.\n";
  }else{
    cout<<count<<endl;
  }
  return 0;
}

/*
input  
5 12
1 1 3 2 8

output : 

*/