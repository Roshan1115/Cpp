/*
given an array and integer k, output the element which are distinct and their number should be k+1/
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
  int n, k; cin >>n >>k;
  vi a(n);
  rep(i,0,n)
    cin>> a[i];
  
  map<int, int> freq;
  rep(i,0,n){
    int size = freq.size();
    if(freq[a[i]] == 0 && size == k)
      break;
    freq[a[i]]++;
  }

  vii ans;
  
  for(auto it= freq.begin(); it != freq.end(); it ++){
    if(it->second != 0){
      ans.push_back(make_pair(it->second, it->first));
    }
  }
  sort(ans.begin(), ans.end(), greater<pii>());

  for(auto i : ans){
    cout<< i.second<<" "<< i.first<< endl;
  }
  return 0;
}

/*
input 
6 2
1 2 2 2 3 4

output 
2 3
1 1
*/