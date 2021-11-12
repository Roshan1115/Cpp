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
  string s = "ros";
  int i = 2;
  char ch = 'a' + i;
  string c = s + ch;
  cout<< c;endline;
  return 0;
}

// use : g++ -std=c++11 