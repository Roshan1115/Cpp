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

int coinGameMax(int *arr, int i, int n){
  if( i > n) return 0;

  int ans = 0;
  if(arr[i] > arr[n]) {
    ans += arr[i];
    i++;
  }
  else{
    ans += arr[n];
    n--;
  }

  arr[i] > arr[n] ? i++ : n-- ;

  ans = ans + coinGameMax(arr, i, n);

  return ans;
}

int main(){
  int n; cin>> n;
  int arr[n];
  rep(i,0,n) {
    cin >> arr[i];
  }

  cout<< coinGameMax(arr, 0, n-1); endline;
  return 0;
}

// use : g++ -std=c++11 

/*
4
1 2 3 4

output : 6
*/