#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

struct Time
{
  int hr, min;

  Time(int h, int m) : hr(h), min(m) {}
  Time() { hr = 0, min = 0; }

  Time(const string &time)
  {
    char ch;
    istringstream foo(time);
    foo >> hr >> ch >> min;
  }

  friend ostream &operator<<(ostream &out, const Time &x)
  {
    out << setfill('0') << setw(2) << x.hr << ':';
    return out << setfill('0') << setw(2) << x.min;
  }
};

bool compare(Time a, Time b)
{
  return a.hr < b.hr || (a.hr == b.hr && a.min < b.min);
}

int main()
{
  vector<Time> xs;
  string s;
  while (cin >> s)
    xs.push_back(Time(s));
  sort(xs.begin(), xs.end(), compare);
  for (int i = 0; i < xs.size(); i++)
    cout << xs[i] << ' ';
  cout << endl;

  return 0;
}
