#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> points;
vector<int> parents;

void push(int, int, int, int);

void push(int row, int col, int parent)
{
  points.push_back(make_pair(row, col));
  parents.push_back(parent);
}

int main()
{
  int rowCount, colCount, sRow, sCol, eRow, eCol;
  cin >> rowCount >> colCount >> sRow >> sCol >> eRow >> eCol;
  bool **maze = new bool *[rowCount + 1];
  for (int i = 1; i <= rowCount; i++)
  {
    maze[i] = new bool[colCount + 1];
    string s;
    cin >> s;
    for (int j = 0; j < colCount; j++)
      maze[i][j + 1] = (s[j] == '0');
  }

  int i, row = sRow, col = sCol;
  push(row, col, -1);
  for (i = 0; row != eRow || col != eCol; i++)
  {
    row = points[i].first;
    col = points[i].second;
    int t = row - 1, r = col + 1, b = row + 1, l = col - 1;
    if (t && maze[t][col])
    {
      push(t, col, i);
      maze[t][col] = false;
    }
    if (t && r <= colCount && maze[t][r])
    {
      push(t, r, i);
      maze[t][r] = false;
    }
    if (r <= colCount && maze[row][r])
    {
      push(row, r, i);
      maze[row][r] = false;
    }
    if (b <= rowCount && r <= colCount && maze[b][r])
    {
      push(b, r, i);
      maze[b][r] = false;
    }
    if (b <= rowCount && maze[b][col])
    {
      push(b, col, i);
      maze[b][col] = false;
    }
    if (b <= rowCount && l && maze[b][l])
    {
      push(b, l, i);
      maze[b][l] = false;
    }
    if (l && maze[row][l])
    {
      push(row, l, i);
      maze[row][l] = false;
    }
    if (t && l && maze[t][l])
    {
      push(t, l, i);
      maze[t][l] = false;
    }
  }
  i--;

  vector<int> route;
  while (i != -1)
  {
    route.push_back(i);
    i = parents[i];
  }

  i = route.size();
  cout << i << endl;
  while (i--)
    cout << "(" << points[route[i]].first << "," << points[route[i]].second << ")" << endl;

  return 0;
}