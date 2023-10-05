#include <iostream>
#include <iomanip>

using namespace std;

typedef struct
{
  float coef;
  int exp;
} term;

int q1()
{
  int exp, counts[3] = {0};
  float coef;
  term **terms = new term *[3];

  for (int j = 0; j < 2; j++)
  {
    cin >> counts[j];
    terms[j] = new term[counts[j]];
    for (int i = 0; i < counts[j]; i++)
    {
      cin >> coef >> exp;
      terms[j][i].coef = coef;
      terms[j][i].exp = exp;
    }
  }

  terms[2] = new term[counts[0] * counts[1]];
  for (int i = 0; i < counts[0]; i++)
  {
    for (int j = 0; j < counts[1]; j++)
    {
      coef = terms[0][i].coef * terms[1][j].coef;
      exp = terms[0][i].exp + terms[1][j].exp;
      terms[2][counts[2]].coef = coef;
      terms[2][counts[2]++].exp = exp;
    }
  }

  int i;
  for (i = 0; i < counts[2]; i++)
  {
    for (int j = i + 1; j < counts[2]; j++)
    {
      term *a = &terms[2][i], *b = &terms[2][j];
      if (a->exp < b->exp)
      {
        term t = *a;
        *a = *b;
        *b = t;
      }
      else if (a->exp == b->exp)
      {
        a->coef += b->coef;
        (*b).coef = 0;
        (*b).exp = 0;
      }
    }
    if (terms[2][i].coef == 0)
      break;
  }
  counts[2] = i;

  for (int j = 0; j < 3; j++)
  {
    for (i = 0; i < counts[j]; i++)
    {
      coef = terms[j][i].coef;
      exp = terms[j][i].exp;
      if (i && coef > 0)
        cout << '+';
      cout << setprecision(2) << fixed << coef;
      if (exp == 1)
        cout << 'x';
      else if (exp)
        cout << "x^" << exp;
    }
    cout << endl;
  }
  return 0;
}