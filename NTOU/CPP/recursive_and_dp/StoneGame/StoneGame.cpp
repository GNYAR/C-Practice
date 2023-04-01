#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int n, *arr;
  while (cin >> n)
  {
    if (!n)
      break;

    arr = new int[n];
    for (int i = 0; i < n; i++)
      cin >> arr[i];

    int l = 0, r = n - 1, players[2] = {0};
    for (int i = 0; i < n; i++)
    {
      if (l == r)
      {
        players[i % 2] += arr[l];
        break;
      }

      bool L1gtR1 = arr[l] > arr[r];
      bool L1gtL2 = arr[l] > arr[l + 1];
      bool R2gtL2 = (arr[r - 1] > arr[l + 1]);

      players[i % 2] += ((L1gtR1 && L1gtL2) || R2gtL2) ? arr[l++] : arr[r--];
    }
    cout << (players[0] >= players[1] ? "WIN" : "LOSE") << endl;

    delete arr;
  }

  return 0;
}
