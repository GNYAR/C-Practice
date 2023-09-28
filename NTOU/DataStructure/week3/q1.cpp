// 插入排序法

#include <iostream>

using namespace std;

int main()
{
  int n, *list;
  cin >> n;
  list = new int[n]{0};

  for (int i = 0; i < n; i++)
  {
    int a, k, t;
    cin >> a;

    for (k = 0; k < i; k++)
      if (a < list[k])
        break;
    for (int j = k; j < i + 1; j++)
    {
      t = list[j];
      list[j] = a;
      a = t;
    }

    if (i == 1 || i == 2 || i == n - 1)
    {
      cout << list[0];
      for (int p = 1; p < i + 1; p++)
        cout << " " << list[p];
      cout << endl;
    }
  }

  delete[] list;
}
