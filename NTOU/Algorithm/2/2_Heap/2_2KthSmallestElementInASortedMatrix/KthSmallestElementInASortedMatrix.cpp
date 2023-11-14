#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> p;

int main()
{
  int n, k;
  cin >> n >> k;
  priority_queue<p, vector<p>, greater<p>> pq;
  vector<vector<int>> matrix;
  vector<int> index(n, 0);
  for (int i = 0; i < n; i++)
  {
    vector<int> xs(n);
    for (int j = 0; j < n; j++)
      cin >> xs[j];
    matrix.push_back(xs);
    pq.push(make_pair(xs[0], i));
  }
  k--;
  while (k--)
  {
    int i = pq.top().second;
    if (index[i] < n - 1)
      pq.push(make_pair(matrix[i][++index[i]], i));
    pq.pop();
  }
  cout << pq.top().first << endl;
  return 0;
}

int version_1()
{
  int n, k, x;
  cin >> n >> k;
  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> x;
      pq.push(x);
    }
  }
  k--;
  while (k--)
  {
    pq.pop();
  }
  cout << pq.top() << endl;
  return 0;
}
