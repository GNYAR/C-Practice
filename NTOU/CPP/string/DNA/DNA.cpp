#include <iostream>
#include <vector>

using namespace std;

int main()
{
  string str;
  int n;
  cin >> str >> n;

  string checked;
  for (int i = 0; i < str.length(); i++)
  {
    string term = str.substr(i, n);
    if (term.length() < n || (checked.find(term) != string::npos))
      continue;

    checked += "|" + term;

    int cnt = 0, index = str.find(term);
    while (index != string::npos)
    {
      cnt++;
      index = str.find(term, index + 1);
    }

    cout << "> " << term << " : " << cnt << endl;
  }

  return 0;
}
