#include <iostream>
#include <climits>
#include <vector>

using namespace std;

enum direction
{
  LEFT,
  RIGHT,
  DOWN
};

int size, res = INT_MIN;
vector<vector<int>> matrix;

void dnf(int row, int col, int s, direction d)
{
  s += matrix[row][col];
  if (row + 1 <= size)
    dnf(row + 1, col, s, DOWN);
  if (d != LEFT && col + 1 < size)
    dnf(row, col + 1, s, RIGHT);
  if (d != RIGHT && col)
    dnf(row, col - 1, s, LEFT);
  if (row == size && s > res)
    res = s;
}

int main()
{
  cin >> size;
  matrix.resize(size + 1, vector<int>(size));
  for (int i = 1; i <= size; i++)
  {
    for (int j = 0; j < size; j++)
      cin >> matrix[i][j];
  }
  dnf(0, 0, 0, DOWN);
  cout << res;
  return 0;
}
