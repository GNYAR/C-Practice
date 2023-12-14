#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  long long n, m, x, y;
  cin >> n >> m;
  vector<pair<long long, long long>> ranges;
  n = 0;
  while (m--)
  {
    cin >> x >> y;
    ranges.push_back(make_pair(x, y));
    sort(ranges.begin(), ranges.end());
    long long cnt = 0;
    for (long long i = 0; i < ranges.size(); i++)
    {
      while (i + 1 < ranges.size() && ranges[i + 1].first <= ranges[i].second)
      {
        if (ranges[i].second < ranges[i + 1].second)
          ranges[i].second = ranges[i + 1].second;
        ranges.erase(ranges.begin() + i + 1);
      }
      n = ranges[i].second - ranges[i].first;
      cnt += n * (n + 1);
    }
    cout << cnt << '\n';
  }
  return 0;
}
