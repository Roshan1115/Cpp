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

int main(){
  
  int n; cin >> n;

  string s;  cin >> s;

  int e=1, a=0, ab=0, abc=0;

  rep(i,0,n) {
    if(s[i] == 'a')
      a += e;
    else if(s[i] == 'b')
      ab += a;
    else if(s[i] == 'c')
      abc += ab;
    else if(s[i] == '?')
    {
      abc += 3*abc + ab;
      ab = 3*ab + a;
      a = 3*a + e;
    }
  }

  cout<< abc; endline;

  return 0;
}

// use : g++ -std=c++11 

/*
input
6
ac?b?c

output : 24
*/