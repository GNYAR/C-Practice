#include <iostream>
#include <map>

using namespace std;

struct node
{
	char x;
	node *left, *right;
};

node *tree(string str)
{
	if (str.front() == '(' && str.back() == ')')
	{
		str = str.substr(2, str.size() - 4);
		node *ptr = new node{str.front(), NULL, NULL};
		str = str.substr(2);
		int l = str.find('('), r = 0;
		if (l == 0)
		{
			do
			{
				r = str.find(')', r + 1);
				l = str.find('(', l + 1);
			} while (-1 < l && l < r);
			ptr->left = tree(str.substr(0, r + 1));
			str = str.substr(r + 2);
		}
		else
		{
			ptr->left = new node{str.front(), NULL, NULL};
			str = str.substr(2);
		}
		l = str.find('('), r = 0;
		if (l == 0)
		{
			do
			{
				r = str.find(')', r + 1);
				l = str.find('(', l + 1);
			} while (-1 < l && l < r);
			ptr->right = tree(str.substr(0, r + 1));
		}
		else
		{
			ptr->right = new node{str.front(), NULL, NULL};
		}

		return ptr;
	}
	return NULL;
}

int calculate(node *ptr, map<char, int> m)
{
	if (ptr)
	{
		int l = calculate(ptr->left, m);
		int r = calculate(ptr->right, m);
		if (isdigit(ptr->x))
			return ptr->x - '0';
		switch (ptr->x)
		{
		case '+':
			return l + r;
		case '-':
			return l - r;
		case '*':
			return l * r;
		case '/':
			return l / r;
			break;
		default:
			return m[ptr->x];
			break;
		}
	}
}

int main()
{
	string str;
	getline(cin, str);
	node *root = tree(str);
	map<char, int> m;
	while (getline(cin, str))
		m[str[0]] = str[4] - '0';
	cout << calculate(root, m) << endl;
	return 0;
}
