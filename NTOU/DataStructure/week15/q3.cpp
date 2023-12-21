#include <iostream>
#include <climits>
#include <queue>

using namespace std;

int main()
{
  vector<vector<pair<int, int>>> graph;
  int s, x, y, z;
  cin >> s;
  while (cin >> x >> y >> z)
  {
    if (max(x, y) >= graph.size())
      graph.resize(max(x, y) + 1);
    graph[x].push_back(make_pair(z, y));
  }
  int cnt = graph.size();
  
  vector<int> d(cnt, INT_MAX);
  vector<bool> flags(cnt, true);
  priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
  d[s] = 0;
  pq.push({0, 0, s});
  for (int i = 0; i < cnt; i++)
  {
    x = pq.top()[2];
    flags[x] = false;
    pq.pop();

    for (int j = 0; j < graph[x].size(); j++)
    {
      y = graph[x][j].second;
      z = graph[x][j].first;
      if (flags[y])
      {
        d[y] = min(d[x] + z, d[y]);
        pq.push({z, x, y});
      }
    }
  }
  for (int i = 0; i < cnt; i++)
    cout << i << ": " << d[i] << '\n';

  return 0;
}
