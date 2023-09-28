#include <iostream>
#define MAX 50000

using namespace std;

int main()
{
  int l, p[MAX + 1] = {0};
  cin >> l;

  int i, t;
  cin >> i >> t;
  while (i || t)
  {
    p[i] = t;
    cin >> i >> t;
  }

  int r[MAX + 1] = {0};
  for (i = 1; i <= l; i++)
  {
    int q = 0;
    for (int j = 1; j <= i; j++)
      q = max(q, p[j] + r[i - j]);
    r[i] = q;
  }

  cout << r[l] << endl;

  return 0;
}
