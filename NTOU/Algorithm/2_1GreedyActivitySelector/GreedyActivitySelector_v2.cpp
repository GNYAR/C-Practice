#include <iostream>

using namespace std;

int main()
{
  int i, s, f, tempF = 0;
  while (cin >> i >> s >> f)
  {
    if (s < tempF)
      continue;
    cout << i << " ";
    tempF = f;
  }
  cout << endl;
  return 0;
}
