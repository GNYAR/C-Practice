#include <iostream>

using namespace std;

long t[1000];

long fib(long x)
{
  if (x < 0)
    return 0;

  if (t[x] >= 0)
    return t[x];

  long a = fib(x - 1), b = fib(x - 2);
  t[x] = a + b;
  t[x - 1] = a;
  t[x - 2] = b;
  return a + b;
}

int main()
{
  for (int i = 0; i < 1000; i++)
    t[i] = -1;
  t[0] = 0;
  t[1] = 1;
  t[2] = 1;
  long n;
  cin >> n;
  cout << fib(n);
  return 0;
}
