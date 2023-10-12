#include <iostream>

using namespace std;

int main()
{
	string str;
	cin >> str;
	while (str != "end")
	{
		int s = 0;
		for (int i = str.size() - 1; i >= 0; i--)
		{
			if (str[i] == ')')
				s++;
			else
				s--;
			if (s < 0)
				break;
		}
		cout << (s == 0 ? 1 : -1) << endl;
		cin >> str;
	}
	return 0;
}
