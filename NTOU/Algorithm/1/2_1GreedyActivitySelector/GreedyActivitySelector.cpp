#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int tempI, tempS, tempF;
  vector<int> i, s, f, ans;
  while (cin >> tempI >> tempS >> tempF)
  {
    i.push_back(tempI);
    s.push_back(tempS);
    f.push_back(tempF);
  }

  ans = {i[0]};
  int cnt = i.size(), a = 0;
  for (int n = 1; n < cnt; n++)
  {
    if (s[n] >= f[a])
    {
      ans.push_back(i[n]);
      a = n;
    }
  }

  for (int j = 0; j < ans.size(); j++)
    cout << ans[j] << " ";
  cout << endl;
  return 0;
}
