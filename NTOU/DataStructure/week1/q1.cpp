#include <iostream>

using namespace std;

int main()
{
  long n;
  cin >> n;
  bool isFirst = true;
  for (long i = 2; i <= n; i++)
  {
    int cnt = 0;
    while (n % i == 0)
    {
      cnt++;
      n /= i;
    }
    if (cnt)
    {
      if (cnt == 1)
        cout << (isFirst ? "" : " * ") << i;
      else
        cout << (isFirst ? "" : " * ") << i << '^' << cnt;

      if (isFirst)
        isFirst = false;
    }
  }
  cout << endl;
  return 0;
}
