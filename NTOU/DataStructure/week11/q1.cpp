#include <iostream>
#include <queue>

using namespace std;

int main()
{
	queue<int> q;
	int n, v, l, r;
	cin >> n >> v;
	while (v != -1)
	{
		cin >> l >> r;
		if (q.size())
		{
			while (v != q.front())
			{
				q.push(0);
				q.push(0);
				cout << q.front() << ' ';
				q.pop();
			}
			q.pop();
		}
		cout << v << ' ';
		q.push(l);
		q.push(r);
		cin >> v;
	}
	while (q.size())
	{
		cout << q.front() << ' ';
		q.pop();
	}
	cout << endl;
	return 0;
}
