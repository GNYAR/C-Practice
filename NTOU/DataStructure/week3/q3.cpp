#include <iostream>

using namespace std;

// Take 1 of the last space part, then put it back to other part with backward sequence
void func(int n, int hints[], int spaces[], int spaceCount, int blacks[])
{
  int last = spaceCount - 1;

  // Return when there is no remain space at last part
  if (spaces[last] == 0)
    return;

  // Take 1 space at last part
  spaces[last]--;
  // Put it back to ith part (n-1 -> 0)
  for (int i = last - 1; i >= 0; i--)
  {
    // Calculate the position of the space
    int k = spaces[0];
    for (int j = 1; j <= i; j++)
      k += hints[j - 1] + spaces[j];
    // Set 0 in blacks and increase the space counter
    blacks[k] = 0;
    spaces[i]++;

    // recursive
    func(n, hints, spaces, spaceCount, blacks);

    spaces[i]--;
  }
  spaces[last]++;
}

int main()
{
  int n, *hints, hintCount = 0, temp, *spaces, *blacks;
  cin >> n;

  // init blacks (all 1) - turn to 0 if the space set in any case
  blacks = new int[n];
  for (int i = 0; i < n; i++)
    blacks[i] = 1;
  // get hints (input)
  hints = new int[n]{0};
  while (cin >> temp)
    hints[hintCount++] = temp;
  // init spaces (align left) and set 0 in blacks
  temp = 0;
  spaces = new int[hintCount + 1]{0};
  for (int i = 0; i < hintCount; i++)
  {
    temp += hints[i];

    if (i == hintCount - 1)
    {
      spaces[hintCount] = n - temp;
      while (temp < n)
        blacks[temp++] = 0;
      break;
    }

    blacks[temp] = 0;
    spaces[i + 1] = 1;
    temp++;
  }

  // recursive
  func(n, hints, spaces, hintCount + 1, blacks);

  // print answer
  cout << blacks[0];
  for (int i = 1; i < n; i++)
    cout << ' ' << blacks[i];

  delete[] hints, spaces;
  return 0;
}
