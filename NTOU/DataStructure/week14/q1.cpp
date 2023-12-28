#include <iostream>
#define MAX 100

using namespace std;

int main()
{
  int x, y, n = -1;
  bool m[MAX][MAX] = {false};
  while (cin >> x >> y)
  {
    n = max(n, max(x, y));
    m[x][y] = true;
    m[y][x] = true;
  }
  cout << "Adjacency matrix:\n";
  for (int i = 0; i <= n; i++)
  {
    cout << (m[i][0] ? 1 : 0);
    for (int j = 1; j <= n; j++)
      cout << ' ' << (m[i][j] ? 1 : 0);
    cout << '\n';
  }
  cout << "\nAdjacency list:\n";
  for (int i = 0; i <= n; i++)
  {
    cout << i << ": ";
    for (int j = 0; j <= n; j++)
    {
      if (m[i][j])
        cout << j << " -> ";
    }
    cout << "end\n";
  }
  return 0;
}
