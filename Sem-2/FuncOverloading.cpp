#include<iostream>
using namespace std;

void volume(int length){
  cout<<"Volume of square is "<< length*length*length<<endl;
}
void volume(int length, int breadth, int height){
  cout<<"Volume of rectangle is "<<length*breadth*height<<endl;
}
void volume(double radius){
  cout<<"Volume of circle is "<< 3.14* radius * radius<<endl;
}

int main(){
  volume(12);  
  volume(12, 6, 10);  
  volume(5.5);  

  return 0;
}