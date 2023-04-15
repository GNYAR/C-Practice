#include <iostream>

using namespace std;

int main()
{
  int cnt = 0;
  string str;
  while (cin >> str)
  {
    cout << "AB Circle #" << ++cnt << ":" << endl;
    int cntA = 0, cntB = 0, len = str.size();

    for (int i = 0; i < len; i++)
      if (str[i] == 'a')
        cntA++;
      else
        cntB++;

    int minAB = min(cntA, cntB), maxAB = max(cntA, cntB);
    for (int i = 0; i + minAB < len; i++)
    {
      if (cntA != cntB)
      {
        cout << i << "," << i + minAB << endl;
        if (i + maxAB < len)
          cout << i << "," << i + maxAB << endl;
      }
      else
      {
        cout << i << "," << i + cntA << endl;
      }
    }
    cout << endl;
  }

  return 0;
}
