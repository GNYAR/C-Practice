#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
  int k;
  string msg;
  cin >> k >> msg;

  unsigned long long s = 0x0;
  for (int i = 0; msg[i]; i++)
  {
    int n = msg[i] - 64 + k;
    if (n > 26)
      n - 26;

    s <<= 5;
    s += n;
  }

  stringstream strStream;
  strStream << hex << s;
  string str = strStream.str();
  cout << str << string(4 - (str.size() % 4), '0') << endl;
}
