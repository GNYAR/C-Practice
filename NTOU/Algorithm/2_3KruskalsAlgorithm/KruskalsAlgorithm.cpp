#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
  int a, b, w, i;
};

vector<vector<Edge>> edgeSets;
vector<vector<int>> nodeSets;

int setFind(int);
void setsUnion(int, int);
void setsPush(Edge);

int setFind(int x)
{
  for (int i = 0; i < nodeSets.size(); i++)
  {
    int l = 0, r = nodeSets[i].size() - 1;
    while (l <= r)
    {
      int m = (l + r) / 2;
      int v = nodeSets[i][m];
      if (x == v)
        return i;
      if (x < v)
        r = m - 1;
      else
        l = m + 1;
    }
  }
  return -1;
}

void setsUnion(int a, int b)
{
  edgeSets[a].insert(edgeSets[a].end(), edgeSets[b].begin(), edgeSets[b].end());
  edgeSets.erase(edgeSets.begin() + b);

  nodeSets[a].insert(nodeSets[a].end(), nodeSets[b].begin(), nodeSets[b].end());
  sort(nodeSets[a].begin(), nodeSets[a].end(), [](int a, int b)
       { return a < b; });
  nodeSets.erase(nodeSets.begin() + b);
};

void setsPush(Edge e)
{
  edgeSets.push_back({e});
  nodeSets.push_back({e.a, e.b});
};

int main()
{
  vector<int> adjacency[40000];
  vector<Edge> edges;

  Edge e;
  while (cin >> e.a >> e.b >> e.w)
  {
    edges.push_back(e);
    adjacency[e.a].push_back(e.b);
    adjacency[e.b].push_back(e.a);
  }

  cout << "Adjacency list:" << endl;
  for (int i = 0; adjacency[i].size(); i++)
  {
    cout << i << ": ";
    for (int j = 0; j < adjacency[i].size(); j++)
      cout << adjacency[i][j] << " -> ";
    cout << "end" << endl;
  }

  sort(edges.begin(), edges.end(), [](Edge a, Edge b)
       { return a.w < b.w; });

  e = edges.front();
  e.i = 0;
  setsPush(e);
  for (int i = 1; i < edges.size(); i++)
  {
    e = edges[i];
    e.i = i;
    int iA = setFind(e.a);
    int iB = setFind(e.b);

    if (iA == iB)
    {
      if (iA < 0)
        setsPush(e);
      continue;
    }

    if (iA < 0 || iB < 0)
    {
      setsPush(e);
      setsUnion(max(iA, iB), edgeSets.size() - 1);
    }
    else
    {
      edgeSets[iA].push_back(e);
      setsUnion(iA, iB);
    }
  }

  cout << endl;
  cout << "minimum spanning tree:" << endl;
  vector<Edge> edgeSet = edgeSets.front();
  sort(edgeSet.begin(), edgeSet.end(), [](Edge a, Edge b)
       { return a.i < b.i; });
  int cost = 0;
  for (int i = 0; i < edgeSet.size(); i++)
  {
    cout << i + 1 << ": <" << edgeSet[i].a << ',' << edgeSet[i].b << '>' << endl;
    cost += edgeSet[i].w;
  }

  cout << endl;
  cout << "The cost of minimum spanning tree: " << cost << endl;

  return 0;
}
