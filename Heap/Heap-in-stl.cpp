#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
  // declaring max heap
  priority_queue<int, vector<int> > pq; 

  pq.push(2);
  pq.push(3);
  pq.push(5);
  pq.push(4);

  cout<< pq.top()<< endl;   // return the max element

  pq.pop(); // delete the max element

  cout<< pq.top()<< endl;



  cout<<"\nNow the min heap.\n";

  // declaring min heap
  priority_queue<int, vector<int>, greater<int> > pqm;
  pqm.push(4);
  pqm.push(12);
  pqm.push(2);
  pqm.push(6);

  cout<< pqm.top()<< endl;

  pqm.pop(); // delete the min element

  cout<< pqm.top()<< endl;

  return 0;
}