/*
long question. include truck, fuel stop and the town
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
  int t; cin >> t;

  while(t--){
    int n; cin >> n;

    vii a(n);
    rep(i,0,n){
      // first is distance (town-stop), second is fuel available in stop
      cin >> a[i].first >> a[i].second;
    }
    // is distance from town to truck, p is available fuel
    int l, p; cin >> l >> p;
    bool redFlag = 0;

    rep(i,0,n){
      a[i].first = l- a[i].first;
    }

    sort(a.begin(), a.end());
    int ans = 0, cur = p;
    
    // max heap
    priority_queue<int, vi > pq;

    rep(i,0,n){
      if(cur >= l){
        break;
      }
      while(cur < a[i].first){
        if(pq.empty()){
          redFlag = 1;
          break;
        }
        ans++;
        cur += pq.top();
        pq.pop();
      }
      if(redFlag) break;

      pq.push(a[i].second);
    }

    if(redFlag){
      cout<<"-1"<<endl;
      continue;
    }

    while(!pq.empty() && cur < l){
      ans ++ ;
      cur += pq.top();
      pq.pop();
    }

    if(cur < l){
      cout<< "-1"<<endl;
      continue;
    }
    else{
      cout<< ans << endl;
    }
  }
  return 0;
}

// use : g++ -std=c++11 


/*
input
1
4
4 4
5 2
11 5
15 10
25 10

output : 2
*/