#include <iostream>
#include <vector>

using namespace std;

class Queens
{
private:
  int n;
  vector<vector<string>> result;
  vector<string> temp;
  bool validPosition(int, int);

public:
  Queens(int);
  void locateQueen(int, int);
  vector<vector<string>> getResult();
};

bool Queens::validPosition(int row, int col)
{
  for (int i = 0; i < this->n; i++)
    if (this->temp[row][i] == 'Q' || this->temp[i][col] == 'Q')
      return false;

  int i = row, j = col;
  while (i >= 0 && j >= 0)
    if (this->temp[i--][j--] == 'Q')
      return false;

  i = row;
  j = col;
  while (i >= 0 && j < this->n)
    if (this->temp[i--][j++] == 'Q')
      return false;

  return true;
}

Queens::Queens(int n)
{
  this->n = n;
  for (int i = 0; i < n; i++)
    this->temp.push_back(string(n, '.'));
}

void Queens::locateQueen(int row, int col)
{
  if (col == this->n)
  {
    this->result.push_back(this->temp);
    return;
  }

  if (row >= this->n)
    return;

  for (int i = 0; i < this->n; i++)
  {
    if (this->validPosition(row, i))
    {
      this->temp[row][i] = 'Q';
      this->locateQueen(row + 1, col + 1);
      this->temp[row][i] = '.';
    }
  }
}

vector<vector<string>> Queens::getResult()
{
  return this->result;
}

int main()
{
  int n;
  while (cin >> n)
  {
    Queens game(n);
    game.locateQueen(0, 0);
    cout << game.getResult().size() << endl;
  }

  return 0;
}
