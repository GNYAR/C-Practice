#include <iostream>

using namespace std;

int main()
{
  char input[14];
  while (cin >> input)
  {
    int base = 1, sum = 0;
    int i;
    for (i = 0; i < 12; i++)
    {
      char c = input[i];
      if (c == '-')
        continue;
      int n = int(c) - 48;
      sum += n * base++;
    }

    int r = sum % 11;
    int check = (r == 10) ? 'X' : char(r + 48);
    if (input[i] == check)
    {
      cout << "OK" << endl;
      continue;
    }
    input[i] = check;
    cout << input << endl;
  }

  return 0;
}
