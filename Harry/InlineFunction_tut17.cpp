#include<iostream>
using namespace std;

// When inline keyword is used, the compiler dowsn't call the function instead it copy paste the code of the function defination in the called statement line.
// It is adviced to use inline only in small function definations.
inline int product(int a, int b){
  return a*b;
}

// Static feature in c++
// Static variable is initiallised only once
int showStatic_use(){
  static int c = 0;   // Next time this c will retain the value 1 and will not ve     initiallized as zero.
  c = c + 1;
  return c;
}

// Default line arguement
int defaultArg(int currentValue, float factor = 2.5){
 return currentValue *factor;
}

int main(){
  int a,b;
  cout<<"Producto fo a and b is "<<product(a,b)<<endl;

  cout<<"\n Static variable calling\n";
  showStatic_use();
  cout<<"C value is "<<showStatic_use()<<endl;
  
  cout<<"For 1000 rupee the defaultArg funciton returns with out passing second argumentt: "<<defaultArg(1000)<<endl;

  return 0;
}