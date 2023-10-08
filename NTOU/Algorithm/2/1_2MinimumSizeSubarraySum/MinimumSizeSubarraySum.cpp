#include <iostream>
#define MAX_N 200

using namespace std;

int main()
{
  int n, s;
  cin >> n >> s;
  int *arr = new int[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int x = MAX_N;
  for (int i = 0; i < n; i++)
  {
    int sum = 0, index = i;
    while (sum < s && index < n)
      sum += arr[index++];
    if (sum >= s)
      x = min(x, index - i);
  }
  for (int i = n - 1; i > -1; i--)
  {
    int sum = 0, index = i;
    while (sum < s && index > -1)
      sum += arr[index--];
    if (sum >= s)
      x = min(x, i - index);
  }
  cout << (x == MAX_N ? 0 : x) << endl;

  delete[] arr;
  return 0;
}
