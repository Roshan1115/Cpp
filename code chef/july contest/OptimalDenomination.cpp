// need to verify this problem (This solution is wrong)

#include <iostream>
#include<limits.h>
using namespace std;

int minDivindex = 0;
int maxSalIndex = 0;

int divide_by_minSal(int *arr, int n, int value)
{
  int maxDividedSal = 0;
  int count = 0;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] % value == 0)
    {
      count++;
      if (arr[i] > maxDividedSal)
      {
        maxDividedSal = arr[i];
        minDivindex = i;
      }
    }
  }

  return count;
}

int countNote(int *arr, int n, int value)
{
  int note = 0;
  for (int i = 0; i < n; i++)
  {
    note += arr[i] / value;
  }
  return note;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    int emp[n];
    for (int i = 0; i < n; i++)
    {
      cin >> emp[i];
    }

    int minSal = INT_MAX;
    int maxSal = 0;

    for (int i = 0; i < n; i++)
    {
      minSal = min(minSal, emp[i]);

      if(emp[i] > maxSal){
        maxSal = emp[i];
        maxSalIndex = i;
      }
    }
    int minDivCount = divide_by_minSal(emp, n, minSal);

    if (minDivCount == n)
    {
      emp[minDivindex] = minSal;
    }
    else
    {
      minSal = 1;
      emp[maxSalIndex] = minSal;
    }

    cout << countNote(emp, n, minSal) << endl;
    minDivindex = 0;
    maxSalIndex = 0;
  }

  return 0;
}
