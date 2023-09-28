#include <iostream>

using namespace std;

void printTerm(int c, int e, bool *isFirst);

void printTerm(int c, int e, bool *isFirst)
{
  bool isOne = abs(c) == 1;

  if (*isFirst && !e)
  {
    cout << c;
    *isFirst = false;
    return;
  }

  if (!*isFirst || !e)
  {
    cout << (c < 0 ? " - " : " + ");
    if (!isOne || !e)
      cout << abs(c);
  }
  else
  {
    if (isOne)
      cout << (c < 0 ? "-" : "");
    else
      cout << c;
    *isFirst = false;
  }

  if (e == 1)
    cout << "x";
  else if (e)
    cout << "x^" << e;
}

int main()
{
  int input;
  while (cin >> input)
  {
    bool isFirst = true;
    if (input != 0)
      printTerm(input, 8, &isFirst);

    for (int i = 7; i >= 0; i--)
    {
      cin >> input;

      if (input != 0)
        printTerm(input, i, &isFirst);
    }

    if (isFirst)
      cout << 0;

    cout << endl;
  }

  return 0;
}
