#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  int s, n, i;
  float p, q, a, r;
  cin >> s;
  while (s--)
  {
    cin >> n >> p >> i;
    q = 1 - p;
    a = pow(q, i - 1) * p;
    r = pow(q, n);
    cout << fixed << setprecision(4);
    cout << (a * (1 - pow(r, 100000)) / (1 - r)) << endl;
  }

  return 0;
}

/*
  Round_1：
  第一人：p
  第二人：q*p
  第三人：(q^2)*p

  第k人：(q^(k-1))*p

  Round_2：
  第一人：(q^n)*p
  第二人：(q^n)*q*p
  第三人：(q^n)*(q^2)*p

  第k人：(q^n)*(q^(k-1))*p

  Round_R：
  第一人：(q^(R-1)*n)*p
  第二人：(q^(R-1)*n)*q*p
  第三人：(q^(R-1)*n)*(q^2)*p

  第k個人獲勝的機率：(q^(R-1)*n)*(q^(k-1))*p

  ※使用等比級數整理每個回合獲勝的機率就可以獲得此公式：
  (q^(k-1)*p) * (1-(q^n^R)) / (1-q^n)
  (首項：(q^(k-1)*p)、公比：q^n)
*/
