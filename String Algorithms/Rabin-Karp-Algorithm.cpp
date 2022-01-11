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

int p = 31;
const int N=1e5+7, m=1e9+7;
vector<long long> powers(N);

int main(){
  string s = "na";
  string t = "apna collegena";

  int S = s.size(), T = t.size();

  powers[0] = 1;
  for(int i=1; i<N;i++){
    powers[i] =( powers[i-1]*p) % m;
  }

  vector<long long> h(T+1, 0);
  for(int i=0; i<T; i++){
    h[i+1] = (h[i] + (t[i] - 'a' + 1)* powers[i]) % m ;
  }

  long long h_s = 0;
  for(int i=0;i<S;i++){
    h_s = (h_s + (s[i]-'a'+1)*powers[i]) % m;
  }

  for(int i=0; i+S-1<T; i++){
    long long cur_h = (h[i+S] - h[i] + m)%m;
   
    if(cur_h == (h_s*powers[i])%m)
      cout<<"Found at index "<<i<<endl;
  }
  return 0;
}

// use : g++ -std=c++11 