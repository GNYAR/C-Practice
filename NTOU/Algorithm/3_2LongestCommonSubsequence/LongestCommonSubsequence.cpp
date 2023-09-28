#include <iostream>

using namespace std;

int main()
{
  string a, b;
  cin >> a >> b;

  int rowCount = a.size() + 1;
  int colCount = b.size() + 1;

  int **table = new int *[rowCount];
  for (int i = 0; i < rowCount; i++)
  {
    table[i] = new int[colCount];
    for (int j = 0; j < colCount; j++)
      table[i][j] = 0;
  }

  for (int i = 1; i < rowCount; i++)
  {
    for (int j = 1; j < colCount; j++)
    {
      if (a[i - 1] == b[j - 1])
      {
        table[i][j] = table[i - 1][j - 1] + 1;
        continue;
      }
      int t = table[i - 1][j];
      int l = table[i][j - 1];
      table[i][j] = max(t, l);
    }
  }

  cout << table[rowCount - 1][colCount - 1] << endl;

  return 0;
}
