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

vi prifix_func(string &s){
  int n = s.size();
  vi pi(n, 0);

  for(int i=1;i<n; i++){
    int j= pi[i-1];

    while (j>0 && s[i] != s[j])
    {
      j = pi[j-1];
    }
    if(s[i] == s[j])
    {
      j++;
    }
    pi[i] = j;
  }
  return pi;
}

int main(){
  string s = "na";
  vi prefix = prifix_func(s);

  string t = "apna collegena";

  int pos = -1;
  int i(0), j(0);
  while(i < t.size()){
    if(t[i] == s[j]){
      j++;
      i++;
    }
    else{
      if(j!=0)
        j = prefix[j-1];
      else
        i++;
    }
    if(j == s.size()){
      pos = i-s.size();
      break;
    }
  }
  cout<<pos;endline;
  return 0;
}

// use : g++ -std=c++11 