/*
print the maximum number of every window of given length.
[1,2,3,4] in this first winddow is [1,2,3] for length 3.
*/

#include<iostream>
#include<vector>
#include<deque>
using namespace std;

void printMaxWindow(vector<int> a, int k){
  int n = a.size();
  deque<int> dq;
  vector<int> ans;

  for(int i=0; i<k; i++){
    while(!dq.empty() && a[dq.back()] < a[i]){
      dq.pop_back();
    }
    dq.push_back(i);
  }
  ans.push_back(a[dq.front()]);

  for(int i=k; i<n; i++){
    if(dq.front() == i-k){
      dq.pop_front();
    }
    while(!dq.empty() && a[dq.back()] < a[i]){
      dq.pop_back();
    }
    dq.push_back(i);
    ans.push_back(a[dq.front()]);
  }
  for(int i : ans){
    cout<<i<<" ";
  }cout<<endl;
}

int main(){
  int n, k;
  cin>>n>> k;

  vector<int> a(n);
  for(int &i : a)
    cin>> i;
  
  printMaxWindow(a, k);

  return 0;
}