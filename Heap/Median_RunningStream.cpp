/*
output the median of numbers. the numbers will continue to be inputed while outputing the median.
*/

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define vi vector<int>

//declaring minheap
priority_queue<int, vi, greater<int> > pqMin;

// declaring max heap
priority_queue<int, vi> pqMax;

void insert(int x){
  if(pqMax.size() == pqMin.size()){
    if(pqMax.size() == 0){
      pqMax.push(x);
      return ;
    }
    if(x < pqMax.top()){
      pqMax.push(x);
    }
    else{
      pqMin.push(x);
    }
  }
  else{
    if(pqMax.size() > pqMin.size()){
      if(x >= pqMax.size()){
        pqMin.push(x);
      }
      else{
        int temp = pqMax.top();
        pqMax.pop();
        pqMin.push(temp);
        pqMax.push(x);
      }
    }
    else{
      if(x <= pqMin.top()){
        pqMax.push(x);
      } 
      else{
        int temp = pqMin.top();
        pqMin.pop();
        pqMax.push(temp);
        pqMin.push(x);
      }
    }
  }
}


double findMedian(){
  if(pqMax.size() == pqMin.size()){
    return ((pqMax.top() + pqMin.top())/2.0);
  }
  else if(pqMax.size() > pqMin.size()){
    return pqMax.top();
  }
  else{
    // cout<<"Hellow.\n";
    return pqMin.top();
  }
}


int main(){
  insert(10);
  cout<< findMedian()<<endl;
  insert(15);
  cout<< findMedian()<<endl;
  insert(21);
  cout<< findMedian()<<endl;
  insert(30);
  cout<< findMedian()<<endl;
  insert(18);
  cout<< findMedian()<<endl;
  insert(19);
  cout<< findMedian()<<endl;

  return 0;
}