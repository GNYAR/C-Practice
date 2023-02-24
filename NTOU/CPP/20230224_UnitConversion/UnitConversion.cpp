#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  int n;
  cin >> n;
  while (n--)
  {
    float i;
    cin >> i;
    cout << fixed << setprecision(2);
    cout << (i * 3.306) << " " << (i * 3.95) << endl;
  }
  return 0;
}
