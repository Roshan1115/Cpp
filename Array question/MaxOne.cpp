/*
given an array. find the length of maximum subarray which have
maximum 1s.
given K, You can change K zeros to 1(s);
*/

#include<iostream>
#include<vector>
using namespace std;

int main(){
  int n; cin>>n;
  int k; cin>> k;
  vector<int> arr(n);
  for(int &i : arr)
    cin>> i;

  int ans =0, i = 0, zeroCount = 0; 
  for(int j=0; j<n; j++){
    if(arr[j] == 0) zeroCount++;
    while(zeroCount > k){
      if(arr[i] == 0){
        zeroCount--;
      }
      i++;
    }
    ans = max(ans, j-i+1);
  }

  cout<< ans<<endl;
  return 0;
}

/*
6 2
1 1 0 0 0 1
*/