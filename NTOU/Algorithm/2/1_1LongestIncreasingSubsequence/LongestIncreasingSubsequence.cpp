#include <iostream>
#include <vector>

using namespace std;

int bSearch(vector<int> xs, int x)
{
  int left = 0, right = xs.size();
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

  if (xs[left] > x)
    return left;
  else
    return left + 1;
}

int main()
{
  int n, t;
  vector<int> xs;

  cin >> n >> t;
  xs.push_back(t);
  for (int i = 1; i < n; i++)
  {
    cin >> t;
    if (t > xs.back())
      xs.push_back(t);
    else
      xs[bSearch(xs, t)] = t;
  }

  cout << xs.size() << endl;

  return 0;
}
