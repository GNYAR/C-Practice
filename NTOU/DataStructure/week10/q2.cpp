#include <iostream>

using namespace std;

struct node
{
	int coef, exp;
	node *link;
};

void insert(node *&head, node *x)
{
	node *ptr = head, *pre = NULL;
	while (ptr && ptr->exp > x->exp)
	{
		pre = ptr;
		ptr = ptr->link;
	}

	if (ptr && ptr->exp == x->exp)
	{
		ptr->coef += x->coef;
		delete x;
	}
	else
	{
		x->link = ptr;
		if (pre)
			pre->link = x;
		else
			head = x;
	}
}

void printTerm(node term)
{
	cout << term.coef;
	switch (term.exp)
	{
	case 0:
		break;
	case 1:
		cout << "x";
		break;
	default:
		cout << "x^" << term.exp;
		break;
	}
}

void print(node *head)
{
	printTerm(*head);
	for (node *ptr = head->link; ptr; ptr = ptr->link)
	{
		cout << " + ";
		printTerm(*ptr);
	}
	cout << endl;
}

node *sum(node *p[2])
{
	node *ptr[2] = {p[0], p[1]};
	node *head = NULL;
	for (int i = 0; i < 2; i++)
	{
		while (ptr[i])
		{
			insert(head, new node(*ptr[i]));
			ptr[i] = ptr[i]->link;
		}
	}
	return head;
}

node *product(node *p[2])
{
	node *ptr[2] = {p[0], p[1]};
	node *head = NULL;
	while (ptr[0])
	{
		ptr[1] = p[1];
		while (ptr[1])
		{
			node *x = new node(*ptr[0]);
			x->coef *= ptr[1]->coef;
			x->exp += ptr[1]->exp;
			insert(head, x);
			ptr[1] = ptr[1]->link;
		}
		ptr[0] = ptr[0]->link;
	}
	return head;
}

int q2()
{
	node *head[2] = {NULL, NULL};
	int c, e;
	for (int i = 0; i < 2; i++)
	{
		cin >> c;
		while (c != -1)
		{
			cin >> e;
			insert(head[i], new node{c, e, NULL});
			cin >> c;
		}
	}
	cout << "add = ";
	print(sum(head));
	cout << "mult = ";
	print(product(head));
	return 0;
}
