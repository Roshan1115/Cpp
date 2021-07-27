// find the largest area of a rectangle whose heights are given in array.

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int largest_area(vector<int> arr){
  int maxArea = 0;
  stack<int> st;

  for(int i=0; i<arr.size(); i++){
    while(!st.empty() && arr[st.top()] > arr[i]){
      int height = arr[st.top()];
      int len = i - st.top();
      maxArea = max(maxArea, height*len);
      st.pop();
    }
    st.push(i);
  }

  return maxArea;
}

int main(){
  int n;
  cin>> n;
  vector<int> a(n);  

  for(int &i: a)
    cin >>i;

  cout<< largest_area(a)<< endl;

  return 0;
}
