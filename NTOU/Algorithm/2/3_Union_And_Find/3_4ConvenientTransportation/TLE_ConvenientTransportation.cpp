#include <iostream>
#include <vector>
#define MAX 1000000

using namespace std;

int find(vector<int> &p, int x)
{
  return p[x] < 0 ? x : p[x] = find(p, p[x]);
}

int main()
{
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int n, m, x, y;
  cin >> n >> m;
  vector<int> parents(n + 1, -1);
  n = 0;
  while (m--)
  {
    cin >> x >> y;
    for (int i = x; i < y; i++)
    {
      int a = find(parents, i), b = find(parents, i + 1);
      if (a == b)
        continue;
      if (parents[a] > parents[b])
        swap(a, b);
      n -= parents[a] * (parents[a] + 1);
      n -= parents[b] * (parents[b] + 1);
      parents[a] += parents[b];
      parents[b] = a;
      n += parents[a] * (parents[a] + 1);
    }
    cout << n << '\n';
  }
  return 0;
}
