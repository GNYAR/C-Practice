#include <iostream>
#define MAX 8000

using namespace std;

int main()
{
  int n, i, w, v, maxI = -1;
  cin >> n;
  // items(weight, value)
  pair<int, int> *items = new pair<int, int>[MAX];
  for (int j = 0; j < MAX; j++)
    items[j] = make_pair(NULL, NULL);
  cin >> i >> w >> v;
  while (i > -1 || w > -1 || v > -1)
  {
    maxI = max(i, maxI);
    items[i] = make_pair(w, v);
    cin >> i >> w >> v;
  }

  // pack(isPut, value)
  pair<bool, int> **pack = new pair<bool, int> *[maxI + 1];
  for (i = 0; i <= maxI; i++)
  {
    pack[i] = new pair<bool, int>[n + 1];
    for (int j = 0; j <= n; j++)
      pack[i][j] = make_pair(false, 0);
  }

  for (i = 0; i < maxI; i++)
  {
    w = items[i].first;
    v = items[i].second;

    if (w == NULL)
    {
      if (i)
      {
        for (int j = 0; j <= n; j++)
          pack[i + 1][j].second = pack[i][j].second;
      }
      continue;
    }

    for (int j = 0; j <= n; j++)
    {
      if (w > j)
      {
        pack[i + 1][j].second = pack[i][j].second;
      }
      else
      {
        int putV = pack[i][j - w].second + v;
        int curV = pack[i][j].second;
        pack[i + 1][j].second = max(putV, curV);

        if (putV > curV)
          pack[i][j].first = putV > curV;
      }
    }
  }

  for (i = maxI, w = n; i >= 0; i--)
  {
    if (pack[i][w].first)
    {
      cout << i << " ";
      w -= items[i].first;
    }
  }
  cout << endl
       << pack[maxI][n].second << endl;

  return 0;
}