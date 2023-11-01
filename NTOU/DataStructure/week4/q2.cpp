#include <iostream>

using namespace std;

typedef struct
{
  int x, y, value;
} element;

int main()
{
  int countX, countY, n;
  cin >> countX >> countY >> n;
  element *matrix[2];
  matrix[0] = new element[n];
  matrix[1] = new element[n];

  int *starts = new int[countY]{0};
  for (int i = 0; i < n; i++)
  {
    cin >> matrix[0][i].x >> matrix[0][i].y >> matrix[0][i].value;
    starts[matrix[0][i].y]++;
  }

  for (int i = countY - 1; i > 0; i--)
    starts[i] = starts[i - 1];
  starts[0] = 0;
  for (int i = 2; i < countY; i++)
    starts[i] += starts[i - 1];

  for (int i = 0; i < n; i++)
  {
    element e = matrix[0][i];
    int t = e.x;
    e.x = e.y;
    e.y = t;
    matrix[1][starts[e.x]++] = e;
  }

  cout << countY << ' ' << countX << ' ' << n << endl;
  for (int i = 0; i < n; i++)
    cout << matrix[1][i].x << ' '
         << matrix[1][i].y << ' '
         << matrix[1][i].value << endl;

  for (int i = 0; i < 2; i++)
    delete[] matrix[i];

  return 0;
}