#include <iostream>

using namespace std;

struct Node
{
  int n, d;
};

int main()
{
  Node L, M, R, Target;

  while (cin >> Target.n >> Target.d)
  {
    if (Target.n == 1 && Target.d == 1)
      return 0;

    L.n = 0;
    L.d = 1;
    M.n = 1;
    M.d = 1;
    R.n = 1;
    R.d = 0;
    while (Target.n != M.n || Target.d != M.d)
    {
      int t = Target.n * M.d;
      int m = M.n * Target.d;
      if (t > m)
      {
        cout << "R";
        L = M;
        M.n += R.n;
        M.d += R.d;
      }
      else
      {
        cout << "L";
        R = M;
        M.n += L.n;
        M.d += L.d;
      }
    }
    cout << endl;
  }
  return 0;
}
