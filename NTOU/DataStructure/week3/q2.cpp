// 非連續子序列之兩數最大和

#include <iostream>
#include <climits>

using namespace std;

int main()
{
  int n, max[4]{INT_MIN}, maxI[4]{INT_MIN};
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    int value, index = i, k, t;
    cin >> value;

    for (k = 0; k < 4; k++)
      if (value > max[k])
        break;
    for (int j = k; j < 4; j++)
    {
      t = max[j];
      max[j] = value;
      value = t;

      t = maxI[j];
      maxI[j] = index;
      index = t;
    }
  }

  for (int i = 0; i < 4 && i < n; i++)
  {
    for (int j = i + 1; j < 4 && j < n; j++)
    {
      if (abs(maxI[i] - maxI[j]) > 1)
      {
        cout << max[i] + max[j];
        return 0;
      }
    }
  }
  return 0;
}
