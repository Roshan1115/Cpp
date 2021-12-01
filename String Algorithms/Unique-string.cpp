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

int N = 1e5+3, m = 1e9+7;
vector<long long> powers(N);
int p = 31;


// hashing function
long long calsulate_hash(string w) {
  long long hash;
  rep(i,0,w.size()){
    hash += ((w[i] - 'a' + 1) * powers[i]) % m;
  }
  return hash;
}

int giveunique(vector<string> &s) {
  powers[0] = 1;
  rep(i,1,N) {
    powers[i] = (powers[i-1] * p) % m;
  }
  vector<long long> hashes;
  for(auto w : s){
    hashes.push_back(calsulate_hash(w));
  }

  sort(hashes.begin(), hashes.end());
  // time taken for sort = O(nm)

  int distinct = 0;
  rep(i,0,hashes.size()){
    if(i == 0 || hashes[i] != hashes[i-1])
      distinct++;
  }
  return distinct;
}

int32_t main(){
  vector<string> strings = {"aa", "ab", "aa", "b", "cc", "aa"};
  sort(strings.begin(), strings.end());
  // time taken = O(nm log(n)) m is individual string size

  int distinct = 0;
  rep(i,0,strings.size()){
    if(i == 0 || strings[i] != strings[i-1])
      distinct++;
  }
  cout<< distinct; endline;




  // doing same with hashing
  cout<< giveunique(strings); endline;

}

// use : g++ -std=c++11 