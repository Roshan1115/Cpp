/* check if a given number exist in a 2d array or not.
the catch is that the row and coloumn both will be in sorted order in the given matrix. */

#include<iostream>
using namespace std;


int main(){
  int row,col,target;
  cin>>row >>col;
  cout<<"Enter the numver. ";
  cin>>target;

  cout<<"Enter elements.\n";
  int a[row][col];
  for(int i=0; i<row; i++){
    for(int j=0; j<col; j++)
      cin>>a[i][j];
  }
 
  bool found = false;
  int r = 0;
  int c = col-1;
  while(r<row && c >= 0){
    if( a[r][c] == target) {
      found = true;
      break;
      }
    else if( a[r][c] < target) r++;
    else c--;
  }

  if(found){
    cout<<"The element is there inside the array.\n";
  }
  else cout<<"The element is not there inside the array.\n";
  return 0;
}