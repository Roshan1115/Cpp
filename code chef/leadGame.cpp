#include<iostream>
using namespace std;

int main(){
  int rounds;
  cin>>rounds;
  int score_1[rounds], score_2[rounds];
  int a=0,b=0;

  for(int i = 0; i < rounds; i++){
    int s1, s2;
    cin>>s1>>s2;
    a += s1;  b += s2;
    score_1[i] = a;  score_2[i] = b;
  }

  int max_1=0, max_2=0;
    for(int i = 0; i < rounds; i++){

      int d1=0,d2=0;
      if(score_1[i] > score_2[i]){
        d1 = score_1[i] - score_2[i];
        if(d1>max_1) max_1 = d1;
      }
      else if(score_1[i] < score_2[i]){
        d2 = score_2[i] - score_1[i];
        if(d2>max_2) max_2 = d2;
      }
    }
  if(max_1>max_2){
    cout<<"1"<<" "<<max_1;
  }
  else{
    cout<<"2"<<" "<<max_2;
  }
  return 0;
}