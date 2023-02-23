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

    int i = 1, root = (ball % 2) ? 2 : 3;
    while (i++ < (maxDepth - 1))
    {
      ball = (ball % 2 ? ball + 1 : ball) / 2;
      root = (ball % 2) ? root * 2 : root * 2 + 1;
    }
    cout << root << endl;
  }
  return 0;
}
