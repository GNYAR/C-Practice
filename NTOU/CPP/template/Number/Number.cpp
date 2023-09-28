#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 設計一樣板函式，完成找出最小排序數的功能
template <typename T>
void smallestNumber(T xs)
{
  sort(xs.begin(), xs.end());

  if (xs.size() > 1 && xs[0] == 0)
  {
    int i = 1;
    while (xs[i] == 0)
      i++;
    xs[0] = xs[i];
    xs[i] = 0;
  }
  else if (xs.size() > 1 && xs[0] == '0')
  {
    int i = 1;
    while (xs[i] == '0')
      i++;
    xs[0] = xs[i];
    xs[i] = '0';
  }

  for (int i = 0; i < xs.size(); i++)
    cout << xs[i];
  cout << endl;
}

int main()
{
  string str;
  cin >> str;
  smallestNumber(str);
  vector<int> nums;
  transform(str.begin(), str.end(), back_inserter(nums),
            [](char c)
            { return c - '0'; });
  smallestNumber(nums);
}
