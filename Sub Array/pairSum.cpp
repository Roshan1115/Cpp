#include<iostream>
using namespace std;

bool pairSum(int arr[], int n, int k){
  int left = 0;
  int right = n-1;

  while(left<right){
    if(arr[left]+arr[right] ==  k){
      cout<<left<<" and "<<right<<endl;
      return true;
    }
    else if(arr[left]+arr[right] < k){
      left++;
    }
    else right--;
  }
  return false;
}

int main(){
  int SortedArr[] = {2, 4, 7, 11, 14, 16, 20, 21};

  cout<<pairSum(SortedArr, 8, 31);

  return 0;
}