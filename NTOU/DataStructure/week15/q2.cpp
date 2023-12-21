#include <iostream>
#include <queue>

using namespace std;

int main()
{
	vector<vector<pair<int, int>>> graph;
	int s, x, y, z, n, cnt = 0;
	cin >> s;
	while (cin >> x >> y >> z)
	{
		if (max(x, y) >= graph.size())
			graph.resize(max(x, y) + 1);
		graph[x].push_back(make_pair(z, y));
		graph[y].push_back(make_pair(z, x));
	}
	x = s;
	s = graph.size();
	n = 0;
	vector<vector<bool>> flags(s, vector<bool>(s, true));
	priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
	while (n < s - 1)
	{
		for (int i = 0; i < graph[x].size(); i++)
		{
			y = graph[x][i].second;
			z = graph[x][i].first;
			if (flags[x][y])
			{
				pq.push({z, x, y});
				flags[x][y] = flags[y][x] = false;
			}
		}
		vector<int> e = pq.top();
		pq.pop();
		cout << ++n << ": <" << e[1] << ',' << e[2] << ">\n";
		cnt += e[0];
		x = e[2];
	}
	cout << "\nThe cost of minimum spanning tree: " << cnt << '\n';
	return 0;
}
