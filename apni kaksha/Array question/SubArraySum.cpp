#include<iostream>
using namespace std;

int main(){
  int n,s;
  cout<<"Enter array size and the number. ";
  cin>>n>>s;
  cout<<n<<" "<<s<<endl;
  int arr[n];
  cout<<"Enter elemtnts.\n";
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }
  for(int i=0; i<n; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  int i=0, j=0, start=-1, end=-1, currentSum=0;
  
  while(j<n && currentSum <= s){
    currentSum += arr[j];
    j++;
  }

  if(currentSum==s){
      cout<<i<<" "<<j-1<<endl;
      return 0;
    }
    cout<<"i = "<<i<<" j = "<<j<<" sum = "<<currentSum<<endl;

  while(j<n){
    
    while(currentSum > s){
      currentSum -= arr[i];
      i++;
    }
    if(currentSum == s){
      start = i;
      end = j-1;
    }
    
    currentSum += arr[j];
    j++;
  }
  cout<<start<<" "<<end<<endl;
  return 0;
}