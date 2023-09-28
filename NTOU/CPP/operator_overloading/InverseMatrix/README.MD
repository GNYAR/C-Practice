# Inverse Matrix

矩陣 A 為 2 × 2 的方陣，請試著找出矩陣 A 的反矩陣 `adjA / det`，若方陣函式 det(A) 為 0 則輸出`singular matrix` (奇異矩陣是不可逆的方陣) 。

```
Matrix A:
  |  1  2 |
  |  3  4 |

det = (1 * 4) - (2 * 3)

adjA:
  |  4 -2 |
  | -3  1 |
```

```
Matrix A:
  | a11 a12 |
  | a21 a22 |
```

請完成下方程式碼中 `<<` 和 `>>` 運算子多載 (operator overloading)，以及 `matrix::inverse()` 進行反矩陣的計算

```cpp
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

int main()
{
  matrix matrix_A;
  cin >> matrix_A;
  matrix_A.inverse();
  cout << matrix_A;
}
```

## Input

第一行有兩個數，分別對應 `a11` 和 `a12`，兩個數之間有空格隔開。

第二行兩個數分別對應 `a21` 和 `a22`，兩個數之間有空格隔開。

## Output

若方陣函式 det(A)=0 則輸出 `singular matrix` (奇異矩陣)

若方陣函式 det(A)≠0 則輸出結果，

第一行有兩個數，分別對應 `a11′` 和 `a12′`，兩個數之間有空格隔開。

第二行兩個數分別對應 `a21′` 和 `a_22′`，兩個數之間有空格隔開。

註：輸出結果用四捨五入取小數點第一位

## Sample

Input

```
3 1
2 4
```

Output

```
0.4 -0.1
-0.2 0.3
```
