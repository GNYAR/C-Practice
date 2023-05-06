#include <iostream>
#include <regex>
#include <vector>

using namespace std;

vector<string> split(string, string);

vector<string> split(string str, string sep)
{
  vector<string> xs;
  int head = 0, i = str.find(sep);
  while (i != string::npos)
  {
    xs.push_back(str.substr(head, i - head));
    head = i + 1;
    i = str.find(sep, head);
  }
  xs.push_back(str.substr(head));
  return xs;
}

int main()
{
  string str;
  while (cin >> str)
  {

    regex ipv4("\\d+[.]\\d+[.]\\d+[.]\\d+");
    regex ipv6("\\w+:\\w+:\\w+:\\w+:\\w+:\\w+:\\w+:\\w+");

    if (regex_match(str, ipv4))
    {
      bool isPass = true;
      vector<string> xs = split(str, ".");
      for (int i = 0; i < 4; i++)
      {
        int n = atoi(xs[i].c_str());
        bool startWith0 = xs[i].length() != 1 && xs[i][0] == '0';
        bool outOfRange = n < 0 || n > 255;
        if (startWith0 || outOfRange)
        {
          isPass = false;
          break;
        }
      }
      cout << (isPass ? "IPv4" : "N") << endl;
    }
    else if (regex_match(str, ipv6))
    {
      bool isPass = true;
      vector<string> xs = split(str, ":");
      for (int i = 0; i < 8; i++)
      {
        bool hasUnderscore = xs[i].find('_') != string::npos;
        bool wrongLength = xs[i].length() > 4;
        bool aloneChar = xs[i].length() == 1 && xs[i][0] != '0';
        bool fourZero = xs[i] == "0000";
        if (hasUnderscore || wrongLength || aloneChar || fourZero)
        {
          isPass = false;
          break;
        }
      }
      cout << (isPass ? "IPv6" : "N") << endl;
    }
    else
    {
      cout << "N" << endl;
    }
  }

  return 0;
}
