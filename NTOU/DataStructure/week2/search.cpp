#include <iostream>
#define MAX 100
#define COMPARE(x, y) (x < y ? -1 : (x == y ? 0 : 1))

using namespace std;

int search(int list[], int n, int left, int right);

int search(int list[], int n, int left, int right)
{
  int mid = (left + right) / 2;
  switch (COMPARE(n, list[mid]))
  {
  case -1:
    right = mid - 1;
    break;
  case 1:
    left = mid + 1;
    break;
  case 0:
    return mid;
  }
  return search(list, n, left, right);
}

int main()
{
  int n, k, list[MAX], i;
  cin >> n >> k;
  for (i = 0; i < k; i++)
    cin >> list[i];
  cout << search(list, n, 0, i - 1);
  return 0;
}