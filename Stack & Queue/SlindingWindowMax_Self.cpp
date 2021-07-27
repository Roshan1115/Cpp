#include<iostream>
#include<vector>
#include<deque>
using namespace std;

void printMaxWindow(vector<int> arr, int k){
  deque<int> dq(k);
  vector<int> ans;
  int count = 0;
  bool set = false;

  for(int i=0; i<arr.size(); i++){
    count++;
    if(count == k) set = true;

    while(!dq.empty() && arr[i] >= arr[dq.back()]){
      dq.pop_back();
    }
    dq.push_back(i);

    if(set){
      ans.push_back(arr[dq.front()]);

      while(!dq.empty() && dq.front() <= i-k+1){
        dq.pop_front();
      }

    }
  }

  for(int i : ans){
    cout<< i<<" ";
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