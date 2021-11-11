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

class say{
  public:
  say(){
    cout<<"Constructor.\n";
  }
};

int main(){
  say s;
  say *p = new say();

  return 0;
}

// use : g++ -std=c++11 