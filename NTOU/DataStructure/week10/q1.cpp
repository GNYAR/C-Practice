#include <iostream>
#include <string>
#include <climits>

using namespace std;

int getP(string str)
{
	int l = str.find('['), r = str.find(']');
	if (l == -1)
		return r;
	else if (r == -1)
		return l;
	else
		return min(l, r);
}

int main()
{
	string str;
	while (getline(cin, str))
	{
		int p = getP(str);
		string ans = p != -1 ? str.substr(0, p) : str;
		while (p != -1)
		{
			bool isLeft = str[p] == '[';
			str = str.substr(p + 1);
			int nextP = getP(str);
			string x = nextP != -1 ? str.substr(0, nextP) : str;
			if (isLeft)
				ans = x + ans;
			else
				ans = ans + x;
			p = nextP;
		}
		cout << ans << endl;
	}
	return 0;
}
