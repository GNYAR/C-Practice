# Complex Number

複數(Complex number)，為實數的延伸，它使任一多項式方程式都有根。在 C/C++ 中並沒有這一種型態，所以我們要透過類別定義一個新的資料型態來存放複數。

除了基本的存放資料外，也要提供(定義)他們所支援的運算，我們要考慮以下運算：

- 加法

  `(a + bi) + (c + di) = (a + c) + (b + d)i`

- 減法

  `(a + bi) - (c + di) = (a - c) + (b - d)i`

- 乘法

  `(a + bi)(c + di) = (ac - bd) + (bc + ad)i`

- 除法

  `(a + bi) / (c + di) = [(ac + bd) / (c^2 + d^2)] + [(bc - ad) / (c^2 + d^2)]i`

- 絕對值

  `| a + bi | = (a^2 + b^2)^0.5`

- 等量

請完成下方程式碼

```cpp
#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

class Complex
{
  private:
    double m_real;
    double m_imaginary;
  public:
    Complex(void){}
    virtual ~Complex(void){}
    void setValue(double real, double imaginary);
    void add(Complex &rhs);
    void subtract(Complex &rhs);
    void multiply(Complex &rhs);
    bool divide(Complex &rhs);
    bool equal(Complex &rhs, double x);
    double magnitude();
    void print();
};

/*需要完成以下的部分*/
void Complex::setValue(double real, double imaginary)
{
}

void Complex::add(Complex &rhs)
{
  m_real = m_real + rhs.m_real;
  m_imaginary = rhs.m_imaginary + m_imaginary;
}

void Complex::subtract(Complex &rhs)
{
}

void Complex::multiply(Complex &rhs)
{
  double lhsReal, rhsReal;
  lhsReal = m_real;
  rhsReal = rhs.m_real;
  m_real = m_real * rhs.m_real - m_imaginary * rhs.m_imaginary;
  m_imaginary = lhsReal * rhs.m_imaginary + m_imaginary * rhsReal;
}

bool Complex::equal(Complex &rhs ,double x)
{
}

bool Complex::divide(Complex &rhs)
{
}

double Complex::magnitude()
{
}

void Complex::print()
{
  //正數範例 麻煩補上若虛數為負數時的狀況
  cout << "(" << setprecision(5) << m_real << "+" << setprecision(5) << m_imaginary << "i)";
}
/* 須完成以上部分*/

int main()
{
  double input_1, input_2, input_3, input_4, input_5, input_6;
  Complex a, b;
  cin >> input_1 >> input_2 >> input_3 >> input_4;
  cin >> input_5 >> input_6;

  a.setValue(input_1, input_2);
  b.setValue(input_3, input_4);
  cout << "add: " << endl;/*add test*/
  a.print();
  cout << "+";
  b.print();
  a.add(b);
  cout << "=";
  a.print();
  cout << endl;
  /*- - - - - - - - - - - - - - - - - - - - */
  a.setValue(input_1, input_2);
  b.setValue(input_3, input_4);
  cout << "subtract: " << endl;/*subtract test*/
  a.print();
  cout << "-";
  b.print();
  a.subtract(b);
  cout << "=";
  a.print();
  cout << endl;
  /*- - - - - - - - - - - - - - - - - - - - */
  a.setValue(input_1, input_2);
  b.setValue(input_3, input_4);
  cout << "multiply: " << endl;/*multiply test*/
  a.print();
  cout << "*";
  b.print();
  a.multiply(b);
  cout << "=";
  a.print();
  cout << endl;
  /*- - - - - - - - - - - - - - - - - - - - */
  a.setValue(input_1, input_2);
  b.setValue(input_3, input_4);
  cout << "divide: " << endl;/*divide test*/
  a.print();
  cout << "/";
  b.print();
  if(a.divide(b))
  {
    cout << "=";
    a.print();
    cout << endl;
  }
  else
  {
    cout << "error" << endl;
  }
  /*- - - - - - - - - - - - - - - - - - - - */
  a.setValue(3.055,3.055);
  input_5 = input_5 / 2.0 + 1.51;
  input_6 = input_6 / 2.0 + 1.51;
  b.setValue(input_5, input_6);
  cout << "equal: " << endl;/*equal test*/
  a.print();
  if(a.equal(b, 1e-7))
    cout << "==";
  else
    cout << "!=";
  b.print();
  cout << endl;
  /*- - - - - - - - - - - - - - - - - - - - */
  cout << "magnitude: " << endl;
  b.print();
  cout << "=" << setprecision(5) << b.magnitude() << endl;
  return 0;
}
```

## Input

每組輸入共有 6 個數字，分別代表 3 組實數與虛數

## Output

add(加法),subtract(減法),multiply(乘法),Divide(除法)利用前 4 個數字進行計算。

Equel(相等)和 magnitude(複數平面上向量的長度)利用最後 2 個數字進行計算。

具體計算過程請參考範例程式碼。

## Sample

Input

```
2.45
3.55
3.21
3.22
3.09
3.09
```

Output

```
add:
(2.45+3.55i)+(3.21+3.22i)=(5.66+6.77i)
subtract:
(2.45+3.55i)-(3.21+3.22i)=(-0.76+0.33i)
multiply:
(2.45+3.55i)*(3.21+3.22i)=(-3.5665+19.285i)
divide:
(2.45+3.55i)/(3.21+3.22i)=(0.93339+0.16962i)
equal:
(3.055+3.055i)==(3.055+3.055i)
magnitude:
(3.055+3.055i)=4.3204
```
