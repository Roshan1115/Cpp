/*
this is the function that represent the number of numbers from 1 to n-1 which are co-prime with n.



formula
ETF(n) = n * (1-1/p1) * (1-1/p2) * (1-1/p3) + .......

where p1, p2, p3 are prime factors of n
*/

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

const int N = 1e5+2;

int totient[N];

int main(){
  rep(i,0,N)
    totient[i] = i;

  rep(i,2,N){
    if(totient[i] == i){
      for(int j=2*i; j<N; j += i){
        totient[j] *= i-1;
        totient[j] /= i;
      }
      totient[i] = i-1;
    }
  }

  for(int i=2; i<11; i++){
    cout<< totient[i]<<" ";
  }endline;

  return 0;
}

// use : g++ -std=c++11 