#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int rainWaterTapped(vector<int> v){
  int ans = 0;
  stack<int> st;

  for(int i=0; i<v.size(); i++){
    while(!st.empty() && v[st.top()] < v[i]){
      int curr = st.top();
      st.pop();
      if(st.empty()) break;

      int diff = i - st.top() - 1;
      ans += (min(v[st.top()], v[i]) - v[curr]) * diff; 
      // cout<<v[st.top()]<<" "<<v[curr]<<" "<<v[i]<<"  "<<ans<<endl;
    }
    st.push(i);
  }

  return ans;
}

int main(){
  int n; cin>>n;
  vector<int> v(n);
  for(int &i: v)
    cin>> i;

  cout<< rainWaterTapped(v)<<endl;
  return 0;
}

/*
12
0 1 0 2 1 0 1 3 2 1 2 1
*/