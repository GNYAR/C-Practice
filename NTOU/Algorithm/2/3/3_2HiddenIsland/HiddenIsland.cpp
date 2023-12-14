#include <iostream>
#include <vector>
#include <set>
#define MAX 1000

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

  if (p[x] < p[y])
  {
    p[x] += p[y];
    p[y] = x;
  }
  else
  {
    p[y] += p[x];
    p[x] = y;
  }
}

int main()
{
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  vector<int> parents(MAX * MAX, -1);
  int mapping[MAX + 2][MAX + 2], k = 0;
  set<int> keys, s;
  bool matrix[MAX + 2][MAX + 2] = {false};
  for (int i = 1; i <= MAX; i++)
  {
    for (int j = 1; j <= MAX; j++)
      mapping[i][j] = k++;
  }
  int n, x, y;
  cin >> n;
  while (n--)
  {
    cin >> x >> y;
    matrix[x][y] = true;
    k = mapping[x][y];
    if (keys.find(k) == keys.end())
    {
      keys.insert(k);
      if (matrix[x - 1][y])
      {
        s.erase(find(parents, mapping[x - 1][y]));
        joint(parents, k, mapping[x - 1][y]);
      }
      if (matrix[x][y + 1])
      {
        s.erase(find(parents, mapping[x][y + 1]));
        joint(parents, k, mapping[x][y + 1]);
      }
      if (matrix[x + 1][y])
      {
        s.erase(find(parents, mapping[x + 1][y]));
        joint(parents, k, mapping[x + 1][y]);
      }
      if (matrix[x][y - 1])
      {
        s.erase(find(parents, mapping[x][y - 1]));
        joint(parents, k, mapping[x][y - 1]);
      }
      s.insert(find(parents, k));
    }
    cout << s.size() << '\n';
  }
  return 0;
}
