#include <iostream>
#include <queue>

using namespace std;

int main()
{
	vector<vector<vector<int>>> graph; // {id, weight}
	int start, x, y, w;
	cin >> start;
	while (cin >> x >> y >> w)
	{
		if (max(x, y) >= graph.size())
			graph.resize(max(x, y) + 1);
		graph[x].push_back({y, w});
		graph[y].push_back({x, w});
	}

	int n = graph.size(), cnt = 0, cost = 0;
	// [i][j]: is edge(i, j) selected
	vector<vector<bool>> flags(n, vector<bool>(n, false));
	// min heap for edge {weight, v, u}
	priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
	x = start;
	while (cnt < n - 1) // edge count = n - 1
	{
		// push edge into min heap
		for (int i = 0; i < graph[x].size(); i++)
		{
			y = graph[x][i][0];
			w = graph[x][i][1];
			if (!flags[x][y])
			{
				pq.push({w, x, y});
				flags[x][y] = flags[y][x] = true;
			}
		}

		// select the minimum cost edge
		vector<int> e = pq.top();
		pq.pop();
		cost += e[0];
		cout << ++cnt << ": <" << e[1] << ',' << e[2] << ">\n";

		x = e[2];
	}
	cout << "\nThe cost of minimum spanning tree: " << cost << '\n';
	return 0;
}
