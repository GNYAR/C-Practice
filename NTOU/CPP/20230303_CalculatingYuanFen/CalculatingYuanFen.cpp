#include <iostream>
#include <vector>

using namespace std;

bool check(char input[11], int st);

bool check(char input[11], int st)
{
  vector<int> arr;
  for (int i = 0; input[i]; i++)
  {
    vector<int> tmp;
    int n = input[i] + st - 'A';
    while (n)
    {
      tmp.push_back(n % 10);
      n /= 10;
    }
    int size = tmp.size();
    while (size--)
      arr.push_back(tmp[size]);
  }

  while (arr.size() > 3)
  {
    for (int i = 0; i < arr.size() - 1; i++)
      arr[i] = (arr[i] + arr[i + 1]) % 10;
    arr.pop_back();
  }

  return arr == vector<int>{1, 0, 0};
}

int main()
{
  char input[11];
  while (cin >> input)
  {
    bool pass = false;
    for (int i = 1; i <= 10000; i++)
    {
      if (check(input, i))
      {
        pass = true;
        cout << i << endl;
        break;
      }
    }
    if (!pass)
      cout << ":(" << endl;
  }

  return 0;
}
