#include <iostream>

using namespace std;

int main()
{
  int d, r;
  while (cin >> d)
  {
    if (d < 1500)
    {
      cout << 70 << endl;
      continue;
    }
    r = d - 1500;
    cout << 70 + (r / 500 + (r % 500 ? 1 : 0)) * 5 << endl;
  }
  return 0;
}
