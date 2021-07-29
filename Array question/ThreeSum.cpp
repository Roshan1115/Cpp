// given a taget value. find if there exist three numbers whose sum
// is equal to the target with less time than O(n^3).

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int n; cin>>n;
  int target; cin>> target;
  vector<int> arr(n);
  for(int &i : arr)
    cin>> i;
  
  bool found = false;
  sort(arr.begin(), arr.end());

  for(int i=0; i<arr.size(); i++){
    int low = i+1;
    int high = arr.size() -1;

    while(low < high){
      int result = arr[i] + arr[low] + arr[high];
      if(result == target){
        found = true;
        break;
      }
      else if(result < target) low++;
      else if(result > target) high--;
    }
    if(found) break;
  }

  if(found){
    cout<<"True \n";
  }
  else cout<<"False \n";


  return 0;
}

/*
6 24
12 3 6 9 34 25
*/