#include <iostream>
#include <vector>

using namespace std;

int find(vector<int> &parent, vector<int> &total, int x)
{
  int p = x;
  while (parent[p] > 0)
    p = parent[p];
  while (x != p)
  {
    int temp = parent[x];
    parent[x] = p;
    total[x] = p;
    x = temp;
  }
  return p;
}

void joint(vector<int> &parent, vector<int> &total, int p, int q)
{
  p = find(parent, total, p);
  q = find(parent, total, q);
  if (parent[p] < parent[q])
  {
    parent[p] += parent[q];
    parent[q] = p;
    total[p] += total[q];
    total[q] = p;
  }
  else
  {
    parent[q] += parent[p];
    parent[p] = q;
    total[q] += total[p];
    total[p] = q;
  }
}

void move(vector<int> &parent, vector<int> &total, int p, int q)
{
  int pp, qp = find(parent, total, q);
  if (parent[p] < -1)
  {
    pp = 1;
    while (parent[pp] != p)
      pp++;
    parent[pp] = parent[p];
    parent[p] = pp;
    total[pp] = total[p];
    total[p] = pp;
  }
  else
    pp = find(parent, total, p);

  for (int i = 1; i < parent.size(); i++)
  {
    if (parent[i] == p)
      find(parent, total, p);
  }

  parent[pp]++;
  parent[qp]--;
  total[pp] -= p;
  total[qp] += p;
  for (int i = 1; i < parent.size(); i++)
  {
    if (parent[i] == p)
      find(parent, total, p);
  }
  parent[p] = qp;
  total[p] = qp;
}

int main()
{
  int n, m, x, y, z;
  cin >> n >> m;
  vector<int> parent(n + 1, -1);
  vector<int> total(n + 1, 0);
  for (int i = 1; i <= n; i++)
    total[i] = i;

  while (m--)
  {
    cin >> x;
    switch (x)
    {
    case 1:
      cin >> y >> z;
      joint(parent, total, y, z);
      break;
    case 2:
      cin >> y >> z;
      move(parent, total, y, z);
      break;
    case 3:
      cin >> y;
      z = find(parent, total, y);
      cout << parent[z] * -1 << ' ' << total[z] << '\n';
      break;
    default:
      break;
    }
  }

  return 0;
}
