#include <iostream>
#include <climits>

using namespace std;

int search(int *xs, int n, int x)
{
  int left = 0, right = n - 1;
  while (left <= right)
  {
    int middle = (left + right) / 2;
    if (xs[middle] == x)
      return middle;
    else if (xs[middle] > x)
      right = middle - 1;
    else
      left = middle + 1;
  }
  return left >= n ? -1 : left;
}

int main()
{
  int n, s;
  cin >> n >> s;
  int *arr = new int[n], *sums = new int[n + 1]{0}, ans = INT_MAX;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
    sums[i + 1] = sums[i] + arr[i];
  }
  for (int i = 1; i <= n; i++)
  {
    int x = s + sums[i - 1];
    int res = search(sums, n + 1, x);
    if (res > 0)
      ans = min(ans, res - i + 1);
  }
  cout << (ans == INT_MAX ? 0 : ans) << endl;

  delete[] arr, sums;
  return 0;
}
