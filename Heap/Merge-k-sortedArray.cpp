/*
Given integer k arrays, merge them.
*/

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define rep(i,a,b) for(int i=a; i<b; i++)

// forPrinting
#define printV(v) for(auto &i : v)cout<< i<< " ";cout<<endl;

int main(){
  int k; ; cin>> k;

  // equivalent to two dimentional array
  vector< vector<int> > vect(k);

  rep(i, 0, k)
  {
    int size; cin>> size;
    vect[i] = vector<int>(size);
    rep(j,0,size){
      cin>> vect[i][j];
    }
  }

  vector<int> idx(k, 0);

  // declaring minheap
  priority_queue<pii, vector<pii>, greater<pii> > minHeap; 

  // pushig the first element of each array along with their array number
  rep(i,0,k){
    minHeap.push(make_pair(vect[i][0], i));
  }

  vector<int> ans;

  while(!minHeap.empty()){
    pii temp = minHeap.top();
    minHeap.pop();

    ans.push_back(temp.first);

    if(idx[temp.second] + 1 < vect[temp.second].size())
    {
      pii toPush = make_pair(vect[temp.second][idx[temp.second] + 1], temp.second);
      minHeap.push(toPush);
    }
    idx[temp.second]++ ;
  }

  rep(i,0,ans.size())
    cout<< ans[i]<< " ";
  cout<<endl;

  return 0;
}


/*
input : 

3
3
1 4 6
2
2 3
3
5 6 7


output : 1 2 3 4 5 6 6 7 
*/