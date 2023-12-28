#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int count;
  cin >> count;

  vector<vector<int>> a, b, c;

  int n = 0;
  for (int i = 0; i < count; i++)
  {
    char ch;
    int x, y, value;
    cin >> ch >> x >> ch >> y >> ch >> ch >> value;
    a.push_back({x, y, value});
    b.push_back({y, x, value});
    n = max(n, max(x, y));
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  for (int i = 0; i < count; i++)
  {
    int j = 0;
    while (j < count && a[i][1] > b[j][0])
      j++;
    while (j < count && a[i][1] == b[j][0])
    {
      c.push_back({a[i][0], b[j][1], a[i][2] * b[j][2]});
      j++;
    }
  }
  sort(c.begin(), c.end());
  int temp = c[0][2];
  for (int i = 1; i < c.size(); i++)
  {
    if (c[i][0] == c[i - 1][0] && c[i][1] == c[i - 1][1])
      temp += c[i][2];
    else
    {
      cout << c[i - 1][0] << ' ' << c[i - 1][1] << ' ' << temp << endl;
      temp = c[i][2];
    }
  }
  cout << c.back()[0] << ' ' << c.back()[1] << ' ' << temp << endl;

  return 0;
}
