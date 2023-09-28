#include <iostream>
#include <iomanip>

using namespace std;

class matrix
{
private:
  double a11, a12, a21, a22;

public:
  void inverse();
  friend istream &operator>>(istream &, matrix &);
  friend ostream &operator<<(ostream &, matrix &);
};

void matrix::inverse()
{
  double det = (a11 * a22) - (a12 * a21);

  matrix adj;
  adj.a11 = a22;
  adj.a12 = a12 * -1;
  adj.a21 = a21 * -1;
  adj.a22 = a11;

  a11 = det ? adj.a11 / det : NULL;
  a12 = det ? adj.a12 / det : NULL;
  a21 = det ? adj.a21 / det : NULL;
  a22 = det ? adj.a22 / det : NULL;
}

istream &operator>>(istream &in, matrix &x)
{
  in >> x.a11 >> x.a12 >> x.a21 >> x.a22;
  return in;
}

ostream &operator<<(ostream &out, matrix &x)
{
  if (x.a11 == NULL)
  {
    out << "singular matrix";
    return out;
  }

  out << setprecision(1)
      << x.a11 << ' ' << x.a12 << endl
      << x.a21 << ' ' << x.a22;
  return out;
}

int main()
{
  matrix matrix_A;
  cin >> matrix_A;
  matrix_A.inverse();
  cout << matrix_A;
}
