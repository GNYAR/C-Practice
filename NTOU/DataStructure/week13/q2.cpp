#include <iostream>

using namespace std;

int teams[200001], parents[200001], sums[200001];

int findParent(int x)
{
  return (parents[x] < 0 ? x : parents[x] = findParent(parents[x]));
}

bool joint(int x, int y)
{
  x = findParent(x);
  y = findParent(y);
  if (x == y)
    return false;
  parents[x] += parents[y], sums[x] += sums[y];
  parents[y] = x;

  return true;
}

int main()
{
  int number, commands, command, index1, index2, parent1, parent2;
  while (cin >> number >> commands)
  {
    for (int i = 1; i <= number + commands; ++i)
      parents[i] = -1, teams[i] = sums[i] = i;
    while (commands--)
    {
      cin >> command >> index1;
      switch (command)
      {
      case 1:
        cin >> index2;
        joint(teams[index1], teams[index2]);
        break;
      case 2:
        cin >> index2;
        parent1 = findParent(teams[index1]), parent2 = findParent(teams[index2]);
        if (parent1 != parent2)
        {
          sums[parent1] -= index1, ++parents[parent1];
          ++number, teams[index1] = number;
          sums[teams[index1]] = index1, parents[teams[index1]] = -1;
          joint(teams[index1], teams[index2]);
        }
        break;
      default:
        index2 = findParent(teams[index1]);
        cout << -parents[index2] << ' ' << sums[index2] << '\n';
      }
    }
  }
}
