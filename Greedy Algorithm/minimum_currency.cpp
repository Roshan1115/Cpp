/*
given an array of distinct currency and a integer value v, find the minimum number cucrrency required have currency equal to v
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
  vi a ={1,2,5,10,20,50,100,500,2000};

  sort(a.begin(), a.end(), greater<int>());

  int v; cin>> v;

  map<int,int> ans;
  int i=0;
  while(v > 0){
    if(a[i] <= v){
      ans[a[i]] = v/a[i];
      v = v % a[i];
    }else{
      i++;
    }
  }

  for(auto it = ans.begin(); it != ans.end(); it++){
    cout<<it->first<<" x "<<it->second<<"   ";
  }
  cout<< endl;

  return 0;
}