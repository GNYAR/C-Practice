#include <iostream>
#include <string>
#define SIZE 50

using namespace std;

void push(char stack[], int &top, char x)
{
	stack[++top] = x;
}

char pop(char stack[], int &top)
{
	return stack[top--];
}

int getLevel(char c)
{
	switch (c)
	{
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	default:
		return 0;
	}
}

int main()
{
	char stack[SIZE];
	int n, top;
	cin >> n;
	cin.get();
	while (n--)
	{
		top = -1;
		string str, ans = "";
		getline(cin, str);
		for (int i = 0; i < str.size(); i++)
		{
			switch (str[i])
			{
			case ' ':
				if (ans.size() && isalnum(ans.back()))
					ans += ' ';
				break;
			case '+':
			case '-':
			case '*':
			case '/':
				while (getLevel(stack[top]) >= getLevel(str[i]))
				{
					ans += pop(stack, top);
					ans += ' ';
				}
			case '(':
				push(stack, top, str[i]);
				break;
			case ')':
				while (stack[top] != '(')
				{
					ans += pop(stack, top);
					ans += ' ';
				}
				pop(stack, top);
				break;
			default:
				ans += str[i];
			}
		}

		while (top > -1)
		{
			if (ans.back() != ' ')
				ans += ' ';
			ans += pop(stack, top);
		}

		cout << ans << endl;
	}
	return 0;
}
