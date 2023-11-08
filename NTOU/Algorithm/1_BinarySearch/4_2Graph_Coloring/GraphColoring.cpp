#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_COUNT 300

using namespace std;

int n, maxSize = 0;
vector<vector<int>> adjPoints(MAX_COUNT + 1);
vector<bool> isBlack(MAX_COUNT + 1, false);
vector<int> temp, ans;

void compute(int);

void compute(int i)
{
  if (i > n)
  {
    if (temp.size() > maxSize || temp.size() == maxSize && isBlack[n])
    {
      maxSize = temp.size();
      ans.assign(temp.begin(), temp.end());
    }
    return;
  }

  bool hasBlackAdj = false;
  for (vector<int>::iterator iter = adjPoints[i].begin(); iter != adjPoints[i].end(); iter++)
  {
    if (isBlack[*iter])
    {
      hasBlackAdj = true;
      break;
    }
  }

  if (!hasBlackAdj)
  {
    isBlack[i] = true;
    temp.push_back(i);

    compute(i + 1);

    isBlack[i] = false;
    temp.pop_back();
  }

  compute(i + 1);
};

int main()
{
  int m, k;
  cin >> m;
  while (m--)
  {
    cin >> n >> k;
    while (k--)
    {
      int a, b;
      cin >> a >> b;
      adjPoints[a].push_back(b);
      adjPoints[b].push_back(a);
    }

    compute(1);

    cout << maxSize << endl;
    vector<int>::iterator iter;
    for (iter = ans.begin(); iter != ans.end() - 1; iter++)
      cout << *iter << ' ';
    cout << *iter << endl;

    maxSize = 0;
    temp.clear();
    for (int i = 1; i <= n; i++)
    {
      adjPoints[i].clear();
      isBlack[i] = false;
    }
  }

  return 0;
}
