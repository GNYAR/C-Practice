#include <iostream>
#define MAX 101
#define SWAP(x, y, t) (t = x, x = y, y = t)

using namespace std;

int main()
{
  int n, list[MAX], t;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> list[i];
  for (int i = 0; i < n; i++)
  {
    int min = i;
    for (int j = i + 1; j < n; j++)
    {
      if (list[j] < list[min])
        min = j;
    }
    SWAP(list[i], list[min], t);
  }

  for (int i = 0; i < n; i++)
    cout << list[i] << ' ';
}
