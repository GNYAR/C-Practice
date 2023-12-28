#include <iostream>

using namespace std;

struct term
{
	int coef, exp;
	term *link;
};

void insert(term *&head, int coef, int exp)
{
	if (!head)
	{
		head = new term{coef, exp, NULL};
		return;
	}
	term *ptr = head, *trail = NULL;
	while (ptr && ptr->exp > exp)
	{
		trail = ptr;
		ptr = ptr->link;
	}
	if (ptr && ptr->exp == exp)
		ptr->coef += coef;
	else if (trail)
		trail->link = new term{coef, exp, ptr};
	else
		head = new term{coef, exp, ptr};
}

void print_term(term *x)
{
	switch (x->exp)
	{
	case 0:
		cout << x->coef;
		break;
	case 1:
		cout << x->coef << "x";
		break;
	default:
		cout << x->coef << "x^" << x->exp;
		break;
	}
};

void print(term *head)
{
	if (!head)
		return;
	print_term(head);
	head = head->link;
	while (head)
	{
		cout << " + ";
		print_term(head);
		head = head->link;
	}
	cout << '\n';
}

void delete_list(term *head)
{
	while (head)
	{
		term *temp = head->link;
		delete head;
		head = temp;
	}
}

int main()
{
	term *p[2] = {NULL, NULL}, *res = NULL;
	int coef, exp;
	for (int i = 0; i < 2; i++)
	{
		cin >> coef;
		while (coef != -1)
		{
			cin >> exp;
			insert(p[i], coef, exp);
			insert(res, coef, exp);
			cin >> coef;
		}
	}
	cout << "add = ";
	print(res);
	delete_list(res);

	res = NULL;
	cout << "mult = ";
	term *t[2] = {p[0], NULL};
	while (t[0])
	{
		t[1] = p[1];
		while (t[1])
		{
			coef = t[0]->coef * t[1]->coef;
			exp = t[0]->exp + t[1]->exp;
			insert(res, coef, exp);
			t[1] = t[1]->link;
		}
		t[0] = t[0]->link;
	}
	print(res);

	delete_list(p[0]);
	delete_list(p[1]);
	delete_list(res);
	return 0;
}
