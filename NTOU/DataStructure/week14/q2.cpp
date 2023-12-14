#include <iostream>
#include <vector>

using namespace std;

int find(vector<int> &p, int x)
{
  return p[x] < 0 ? x : p[x] = find(p, p[x]);
}

void joint(vector<int> &p, int x, int y)
{
  x = find(p, x);
  y = find(p, y);
  if (x == y)
    return;
  p[x] += p[y];
  p[y] = x;
}

int main()
{
  int n, x;
  cin >> n;
  vector<int> parents(n, -1);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> x;
      if (x)
        joint(parents, i, j);
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    if (parents[i] < 0)
      cnt++;
    if (cnt > 1)
      break;
  }
  cout << (cnt == 1 ? "1\n" : "-1\n");

  return 0;
}
