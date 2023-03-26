#include <iostream>
#define SIZE 34

using namespace std;

int func1(int n, int k, int R[SIZE][SIZE], int n1, int k1, int *cnt);
int func2(int n, int k, int n1, int k1, int *cnt);

int func1(int n, int k, int R[SIZE][SIZE], int n1, int k1, int *cnt)
{
  if (n == n1 && k == k1)
    *cnt = *cnt + 1;

  if (R[n][k])
    return R[n][k];

  if (k == n || k == 0)
    return 1;

  R[n][k] = func1(n - 1, k, R, n1, k1, cnt) + func1(n - 1, k - 1, R, n1, k1, cnt);
  return R[n][k];
}

int func2(int n, int k, int n1, int k1, int *cnt)
{
  if (n == n1 && k == k1)
    *cnt = *cnt + 1;

  if (k == n || k == 0)
    return 1;

  return func2(n - 1, k, n1, k1, cnt) + func2(n - 1, k - 1, n1, k1, cnt);
}

int main()
{
  int n, k, n1, k1, *cnt;
  while (cin >> n >> k >> n1 >> k1)
  {
    if (n < k)
    {
      cout << "error" << endl;
      continue;
    }

    int R[SIZE][SIZE] = {0};
    cnt = new int(0);
    cout << func1(n, k, R, n1, k1, cnt) << ' ';
    cout << *cnt << ' ';

    *cnt = 0;
    func2(n, k, n1, k1, cnt);
    cout << *cnt << endl;

    delete cnt;
  }

  return 0;
}
