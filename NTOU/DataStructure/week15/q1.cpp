#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<vector<int>> &graph, int x, vector<int> &dfn, vector<int> &low, int &cnt, int p)
{
	dfn[x] = low[x] = cnt++;
	for (int i = 0; i < graph[x].size(); i++)
	{
		int y = graph[x][i];
		if (dfn[y] == -1)
		{
			dfs(graph, y, dfn, low, cnt, x);
			low[x] = min(low[x], low[y]);
		}
		else if (p > -1 && y != p)
			low[x] = min(low[x], dfn[y]);
	}
}

int main()
{
	vector<vector<int>> graph;
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

	vector<int> dfn(graph.size(), -1), low(graph.size(), -1);
	x = 0;
	dfs(graph, 3, dfn, low, x, -1);

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
