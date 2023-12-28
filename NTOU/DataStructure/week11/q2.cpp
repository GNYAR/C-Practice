#include <iostream>
#include <cmath>

using namespace std;

struct node
{
	string value;
	node *left, *right;
};

enum mode
{
	PREODER,
	INODER,
	POSTORDER
};

node *find(node *ptr, string value)
{
	if (ptr)
	{
		if (ptr->value == value)
			return ptr;
		node *left = find(ptr->left, value);
		if (left)
			return left;
		node *right = find(ptr->right, value);
		if (right)
			return right;
	}
	return NULL;
}

void check_level(string value, int &left_level, int &right_level)
{
	int level = value[1] - '0', num = value[2] - '0';
	if (num > pow(2, level - 1))
		right_level = max(right_level, level);
	else
		left_level = max(left_level, level);
}

void print(node *ptr, mode m)
{
	if (ptr)
	{
		switch (m)
		{
		case PREODER:
			cout << ptr->value << ' ';
			print(ptr->left, m);
			print(ptr->right, m);
			break;
		case INODER:
			print(ptr->left, m);
			cout << ptr->value << ' ';
			print(ptr->right, m);
			break;
		case POSTORDER:
			print(ptr->left, m);
			print(ptr->right, m);
			cout << ptr->value << ' ';
			break;
		default:
			break;
		}
	}
}

int main()
{
	node *root = NULL;
	int left_level = 0, right_level = 0;
	string str;
	getline(cin, str);
	while (str != "0")
	{
		int i = str.find(' ');
		string value = str.substr(0, i);
		str = str.substr(i + 1);

		node *ptr;
		if (root)
			ptr = find(root, value);
		else
		{
			root = new node{value, NULL, NULL};
			ptr = root;
		}

		i = str.find(' ');
		if (i > -1)
		{
			value = str.substr(0, i);
			if ((value[2] - '0') % 2)
				ptr->left = new node{value, NULL, NULL};
			else
				ptr->right = new node{value, NULL, NULL};
			check_level(value, left_level, right_level);

			str = str.substr(i + 1);
			if ((str[2] - '0') % 2)
				ptr->left = new node{str, NULL, NULL};
			else
				ptr->right = new node{str, NULL, NULL};
			ptr->right = new node{str, NULL, NULL};
		}
		else
		{
			if ((str[2] - '0') % 2)
				ptr->left = new node{str, NULL, NULL};
			else
				ptr->right = new node{str, NULL, NULL};
		}
		check_level(str, left_level, right_level);

		getline(cin, str);
	}
	cout << "Preorder: ";
	print(root, PREODER);
	cout << endl;
	cout << "Inorder: ";
	print(root, INODER);
	cout << endl;
	cout << "Postorder: ";
	print(root, POSTORDER);
	cout << endl;
	cout << "The balance factor is " << (left_level - right_level) << endl;
	return 0;
}
