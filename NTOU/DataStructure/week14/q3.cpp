#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>> list, int x, vector<bool> &flags)
{
  if (x)
    cout << ' ' << x;
  else
    cout << x;
  flags[x] = true;
  for (int i = 0; i < list[x].size(); i++)
  {
    if (!flags[list[x][i]])
      dfs(list, list[x][i], flags);
  }
}

int main()
{
  int x, y;
  vector<vector<int>> list;
  while (cin >> x >> y)
  {
    if (max(x, y) + 1 > list.size())
      list.resize(max(x, y) + 1);
    list[x].push_back(y);
    list[y].push_back(x);
  }

  cout << "Depth First Search:\n";
  vector<bool> flags(list.size(), false);
  dfs(list, 0, flags);

  cout << "\n\nBreadth First Search:\n";
  flags.clear();
  flags.resize(list.size(), false);
  x = 0;
  int i = 0, j = 0;
  do
  {
    if (x)
      cout << ' ' << x;
    else
      cout << x;
    flags[x] = true;
    do
    {
      if (j < list[i].size())
        x = list[i][j++];
      else
      {
        x = ++i;
        j = 0;
      }
    } while (flags[x]);
  } while (i < list.size());
  cout << '\n';

  return 0;
}
