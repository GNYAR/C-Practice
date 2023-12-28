#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int n, m;
  string str;
  cin >> n >> m >> str;
  vector<int> dp(n, 0);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    { // find max(dp[n - m] + m)
      int k = i - j, temp = 0;
      if (k < 0)
        break;
      if (k > 0)
        temp = dp[k - 1];
      temp += stoi(str.substr(k, j + 1));
      if (temp > dp[i])
        dp[i] = temp;
    }
  }
  cout << dp.back() << '\n';
  return 0;
}
