// put n items of given weight and value in a knapsack of capacity w
// to get the maximum total value in the knapsack

#include<iostream>
using namespace std;

int knapsack(int value[], int wt[], int n, int capacity){

  if(n==0 || capacity== 0){
    return 0;
  }

  if(wt[n-1]>capacity){
    return knapsack(value, wt, n-1, capacity);
  }

  return max(knapsack(value, wt, n-1, capacity-wt[n-1])+value[n-1] , 
  knapsack(value, wt, n-1, capacity));
}

int main(){
  int wt[] ={10, 20, 30};
  int value[] = {100, 50, 150};
  int capacity = 50;

  cout<< knapsack(value, wt, 3, capacity);
  return 0;
}