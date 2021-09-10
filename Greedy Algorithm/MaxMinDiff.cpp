/*
 you are living in array of N elements, remove exactly N/2 elements into different array and find the maximum and minimum difference
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
  int n; cin >> n;
  vi v(n);
  rep(i,0,n)
    cin >> v[i];

  sort(v.begin(), v.end());
  vi v3 = v;

  // for max difference
  vi v2;
  for(int i=0; i< n/2; i++){
    v2.push_back(v.back());
    v.pop_back();
  }
  int maxdif = 0;
  rep(i, 0, n/2){
    maxdif += abs(v2[i] - v[i]);
  }

  // for min difference
  vi v4;
  int mindif = 0;
  rep(i,0,n){
    if(i % 2 == 0){
      continue;
    }
    mindif += abs(v3[i] - v3[i-1]);
  }

  cout<<"Maximum difference : " << maxdif << endl
    <<"Mnimum difference : " << mindif << endl;
  
  return 0;
}

// use : g++ -std=c++11 

/*
input 
4
12 -3 10 0

output :
Maximum difference : 25
Mnimum difference : 5
*/