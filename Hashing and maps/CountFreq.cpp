// given an array, count frequency of each element

#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define rep(i,a,b) for(int i=a; i<b; i++)

int main(){
  int n; cin >> n;
  vi arr(n);

  rep(i,0,n)
    cin >> arr[i];

  map<int, int> freq; // declared map by freq name whith all the key's vale as zero

  rep(i,0,n)
    freq[arr[i]]++ ;

  // another way of traversing the map
  map<int, int> :: iterator it;
  for(it = freq.begin(); it != freq.end(); it++)
    cout<< it->first<<" repeated "<< it->second <<" times.\n";
  cout<< endl;

  
  return 0;
}

/*
input 
8
2 2 5 2 4 4 3 1

output : 
1 repeated 1 times.
2 repeated 3 times.
3 repeated 1 times.
4 repeated 2 times.
5 repeated 1 times.
*/