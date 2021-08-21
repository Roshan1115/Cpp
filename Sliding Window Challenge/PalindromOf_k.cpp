/*
for a given array and integer k, check if any sybarray of size k form a palindrom number.
*/

#include<iostream>
#include<math.h>
using namespace std;

// helper fundtions
int digitNum(int n){
  if(n == 0) return 1;
  int ans=0;
  while(n > 0){
    ans++;
    n = n/10;
  }
  return ans;
}

bool isPalindrom(int n){
  int temp = n, number = 0;
  while(temp > 0){
    number = number * 10 + temp%10;
    temp = temp/10;
  }
  return number == n;
}

void checkPalindrom(int arr[], int n, int k){
  int concate = 0;
  for(int i=0; i<k; i++){
    int digits = digitNum(arr[i]);
    concate = concate * (int)pow(10, digits) + arr[i];
  }
  if(isPalindrom(concate)){
    cout<<"Yes there is a palindrom.\n";
    for(int j=0; j<k; j++)
      cout<<arr[j]<<" ";
    cout<<endl;
    return;
  }
  for(int i=k; i<n; i++){
    int digits = digitNum(arr[i]);
    concate = concate % (int)pow(10,digitNum(concate)-digitNum(arr[i-k]));
    concate = concate * (int)pow(10, digits) + arr[i];

    if(isPalindrom(concate)){
      cout<<"Yes there is a palindrom.\n";
      for(int j=i-k+1; j<=i; j++)
        cout<<arr[j]<<" ";
      cout<<endl;
      return;
    }
  }
  cout<<"No palindrom.\n";
}

int main(){
  int arr[] = {2,3,14,23,32,41};
  int k = 4, n = 6;
  checkPalindrom(arr, n, k);
  return 0;
}
