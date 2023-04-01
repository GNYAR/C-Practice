#include <iostream>
#define MAP_SIZE 10

using namespace std;

class Queens
{
private:
  int cnt;
  bool queen[MAP_SIZE][MAP_SIZE];
  bool validPosition(int, int, int);

public:
  Queens();
  void locateQueen(int, int, int);
  int getCnt();
};

bool Queens::validPosition(int row, int col, int n)
{
  for (int i = 0; i < n; i++)
    if (this->queen[row][i] || this->queen[i][col])
      return false;

  int i = row, j = col;
  while (i >= 0 && j >= 0)
    if (this->queen[i--][j--])
      return false;

  i = row;
  j = col;
  while (i >= 0 && j < n)
    if (this->queen[i--][j++])
      return false;

  return true;
}

Queens::Queens()
{
  this->cnt = 0;
  for (int i = 0; i < MAP_SIZE; i++)
    for (int j = 0; j < MAP_SIZE; j++)
      this->queen[i][j] = false;
}

void Queens::locateQueen(int row, int col, int n)
{
  if (col == n)
  {
    this->cnt++;
    return;
  }

  if (row >= n)
    return;

  for (int i = 0; i < n; i++)
  {
    if (this->validPosition(row, i, n))
    {
      this->queen[row][i] = true;
      this->locateQueen(row + 1, col + 1, n);
      this->queen[row][i] = false;
    }
  }
}

int Queens::getCnt()
{
  return this->cnt;
}

int main()
{
  int n;
  while (cin >> n)
  {
    Queens game;
    game.locateQueen(0, 0, n);
    cout << game.getCnt() << endl;
  }

  return 0;
}
