#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

#define vi vector<int>
#define vii vector<pair<int, int> >
#define pii pair<int, int>
#define rep(i,a,b) for(int i=a; i<b; i++)


void helper(int r,int c,vector<vector<char> > &a,map<pii, map<int,int> > &mp,vector<map<int,int> > &row,vector<map<int,int> > &col){
  if(r == 9){
    for(auto it : a){
      for(auto i : it){
        cout<<i<<" ";
      }cout<< endl;
    }
    cout<<endl;

    exit(0);
  }

  if(c == 9){  
    helper(r+1,0,a,mp,row,col);
    return;
  }

  if(a[r][c] != '.'){   // not empty
    helper(r,c+1,a,mp,row,col);
    return;
  }

  rep(i,0,9){
    int gr = r/3, gc = c/3;   // grid row and column
    bool notInGrid = !mp[{gr,gc}] [i];
    bool notInRow = !row[r][i];
    bool notInCol = !col[c][i];

    if(notInGrid && notInRow && notInCol){
      a[r][c] = i+'0';
      mp[{gr,gc}] [i] = 1;
      row[r][i] = 1;
      col[c][i] = 1;

      helper(r,c+1,a,mp,row,col);   // backtrack

      // undoing
      a[r][c] = '.';
      mp[{gr,gc}] [i] = 0;
      row[r][i] = 0;
      col[c][i] = 0;
    }
  }
}


void solveSudoku(vector<vector<char> > &a){

  // the pii is for denoting the 3x3 sub grid in sudoku
  map<pii, map<int,int> > mp;

  vector<map<int,int> > row(9);
  vector<map<int,int> > col(9);

  rep(i,0,9){
    rep(j,0,9){
      if(a[i][j] != '.'){
        mp[{i/3,j/3}] [a[i][j]-'0'] = 1;
        row[i] [a[i][j]-'0'] = 1;
        col[j] [a[i][j]-'0'] = 1;
      }
    }
  }

  helper(0,0,a,mp,row,col);
}

int main(){
  vector<vector<char> > sudoku = {
    {'5','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'}
  };


  for(auto i : sudoku){
    for(auto j : i)
      cout<< j<< " ";
    cout<<endl;
  }
  cout<<endl<<endl;

  solveSudoku(sudoku);

  return 0;
}