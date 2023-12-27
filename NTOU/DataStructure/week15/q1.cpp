#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<int> dfn, low;
int cnt = 0;

void dfnlow(int v, int parent)
{
	dfn[v] = low[v] = cnt++;
	for (int i = 0; i < graph[v].size(); i++)
	{
		int u = graph[v][i];
		if (dfn[u] == -1)
		{ // unvisited
			dfnlow(u, v);
			low[v] = min(low[v], low[u]);
		}
		else if (parent > -1 && u != parent)
		{ // back edge
			low[v] = min(low[v], dfn[u]);
		}
	}
}

int main()
{
	// adjacency list
	int x, y;
	while (cin >> x >> y)
	{
		if (max(x, y) >= graph.size())
			graph.resize(max(x, y) + 1);

		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	for (int i = 0; i < graph.size(); i++)
		sort(graph[i].begin(), graph[i].end());

	// init
	dfn.resize(graph.size(), -1);
	low = dfn;

	dfnlow(3, -1);

	cout << "   ";
	for (int i = 0; i < graph.size(); i++)
		cout << ' ' << i;
	cout << '\n';

	cout << "dfn";
	for (int i = 0; i < graph.size(); i++)
		cout << ' ' << dfn[i];
	cout << '\n';

	cout << "low";
	for (int i = 0; i < graph.size(); i++)
		cout << ' ' << low[i];
	cout << '\n';

	return 0;
}
