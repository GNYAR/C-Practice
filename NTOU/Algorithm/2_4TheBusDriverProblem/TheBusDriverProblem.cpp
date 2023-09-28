#include <iostream>
#include <algorithm>
#define N_MAX 100

using namespace std;

int main()
{
  int n, d, r;
  cin >> n >> d >> r;
  while (n && d && r)
  {
    int morning[N_MAX], evening[N_MAX];

    for (int i = 0; i < n; i++)
      cin >> morning[i];
    sort(morning, morning + n);

    for (int i = 0; i < n; i++)
      cin >> evening[i];
    sort(evening, evening + n);

    int i = 0, j = n - 1, sum = 0;
    while (n--)
    {
      int l = morning[i++] + evening[j--];
      sum += (l > d) ? (l - d) * r : 0;
    }
    cout << sum << endl;

    cin >> n >> d >> r;
  }

  return 0;
}
