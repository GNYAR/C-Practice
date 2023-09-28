#include <iostream>
#include <vector>
#define MAX 40000

using namespace std;

int main()
{
  vector<pair<int, int>> edges[MAX], ws[MAX];
  int x, y, w;
  while (cin >> x >> y >> w)
  {
    edges[x].push_back(make_pair(y, w));
    edges[y].push_back(make_pair(x, w));
    ws[w].push_back(make_pair(x, y));
  }

  vector<int> ds;
  cout << "Adjacency list:" << endl;
  for (int i = 0; edges[i].size(); i++)
  {
    ds.push_back(i + 1);
    cout << i << ": ";
    for (int j = 0; j < edges[i].size(); j++)
      cout << edges[i][j].first << " -> ";
    cout << "end" << endl;
  }
  cout << endl
       << "minimum spanning tree:" << endl;
  int cost = 0, n = 0;
  for (int i = 0; (i < MAX && n != ds.size() + 1); i++)
  {
    int size = ws[i].size();
    if (size == 0)
      continue;
    for (int j = 0; j < size; j++)
    {
      pair<int, int> e = ws[i][j];
      int s1 = ds[e.first], s2 = ds[e.second];

      if (s1 == s2)
        continue;

      cout << ++n << ": <" << e.first << ',' << e.second << '>' << endl;
      for (int k = 0; k < ds.size(); k++)
      {
        if (ds[k] == max(s1, s2))
          ds[k] = min(s1, s2);
      }
      cost += i;
    }
  }
  cout << endl
       << "The cost of minimum spanning tree: " << cost << endl;
  return 0;
}
