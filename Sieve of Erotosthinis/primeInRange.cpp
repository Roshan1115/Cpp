/* wtire all the prime numbers from 2 to a given number
constraint n < 100
 */

#include <iostream>
using namespace std;

void printPrime(int n)
{
  int prime[100] = {0};
  for (int i = 2; i < n; i++)
  {
    if (prime[i] == 0)
    {

      for (int j = i * i; j <= n; j += i)
      {
        if (prime[j] == 0)
        {
          prime[j] = 1;
        }
      }
    }
  }

  for(int i=2; i<=n; i++){
    if(prime[i] == 0)  cout<<i<<" ";
  }
  cout<<endl;
}

int main()
{
  int n;
  cin >> n;
  printPrime(n);
  return 0;
}