/*
given an array which denotes the stock price. output the numbers of
consicutive day that have lesser price than a[i].
*/

#include<iostream>
#include<stack>
#include<utility>
#include<vector>
using namespace std;

void printDays(vector<int> v){
  vector<int> ans;
  stack<pair<int, int> > st;

  for(int ele : v){
    int days = 1;
    while(!st.empty() && st.top().first < ele){
      days += st.top().second;
      st.pop();
    }

    st.push(make_pair(ele, days));
    ans.push_back(days);
  }

  for(int i : ans)
    cout<< i<<" ";
  cout<<endl;

}

int main(){
  int n; cin>>n;
  vector<int> v(n);
  for(int &i : v)
    cin>> i;

  printDays(v);

  return 0;
}

/*
7
100 80 60 70 60 75 85
*/