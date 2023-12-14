#include <iostream>
#include <vector>
#include <set>
#define MAX 100000

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

  int n;
  cin >> n;
  vector<int> parents(MAX, -1), xs(n), ys(n);
  for (int i = 0; i < n; i++)
    cin >> xs[i];
  for (int i = 0; i < n; i++)
    cin >> ys[i];

  set<int> keys;
  for (int i = 0; i < n; i++)
  {
    keys.erase(find(parents, xs[i]));
    keys.erase(find(parents, ys[i]));
    joint(parents, xs[i], ys[i]);
    keys.insert(find(parents, xs[i]));
  }
  int cnt = 0;
  set<int>::iterator iter;
  for (iter = keys.begin(); iter != keys.end(); iter++)
    cnt -= parents[*iter] + 1;
  cout << cnt << '\n';

  return 0;
}
