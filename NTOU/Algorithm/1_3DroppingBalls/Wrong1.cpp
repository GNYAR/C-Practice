#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  int n, maxDepth, ball;
  cin >> n;
  while (n-- && cin >> maxDepth)
  {
    if (maxDepth == -1)
      return 0;
    cin >> ball;

    int i = 0, root = 1;
    while (i++ < (maxDepth - 1))
    {
      int leafCount = pow(2, i);
      int miniBall = ball % leafCount;
      if (miniBall == 0)
        miniBall = leafCount;

      if (miniBall < root || (miniBall == root && (miniBall % 2)))
        root = root * 2;
      else
        root = root * 2 + 1;
    }
    cout << root << endl;
  }
  return 0;
}
