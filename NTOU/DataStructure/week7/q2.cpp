#include <iostream>

using namespace std;

void printNum(bool& isFirst, int x)
{
	if (isFirst)
	{
		cout << x;
		isFirst = false;
	}
	else
		cout << ' ' << x;
}

int q2()
{
	int a, b;
	cin >> a >> b;
	bool isFirst = true;
	for (int i = a; i <= b; i++)
	{
		int num[3];
		num[2] = i / 100;
		num[1] = i / 10 - num[2] * 10;
		num[0] = i % 10;
		if (num[2] == 0)
		{
			if (num[1] == 0)
				printNum(isFirst, i);
			else if (num[0] == num[1])
				printNum(isFirst, i);
		}
		else if (num[0] == num[2])
			printNum(isFirst, i);
	}

	return 0;
}
