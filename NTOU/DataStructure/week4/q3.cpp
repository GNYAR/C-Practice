#include <iostream>

using namespace std;

int main()
{
  string p, q, r, temp = "";
  getline(cin, p);
  getline(cin, q);
  getline(cin, r);
  int i = 0;
  while (i < p.size())
  {
    if (p[i] == q[0])
    {
      for (int j = 0; j < q.size(); j++)
        temp += p[i++];
      cout << (temp == q ? r : temp);
      temp = "";
    }
    else
    {
      cout << p[i++];
    }
  }
  cout << endl;
  return 0;
}
