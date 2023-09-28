# Timer

有一碼錶，可以顯示分與秒，最多可以計時到十分鐘，若時間超過 10 分鐘則由 0 分 0 秒重新開始。

請完成下方程式碼中 `++`, `--`, `+` 和 `<<` 運算子多載 (operator overloading)

```cpp
#include <iostream>
#include <iomanip>

using namespace std;

const int MAX_MINUTE = 10;

class Timer
{
private:
  int min, sec;
public:
  Timer() : min(0), sec(0) {}
  Timer(int s) : min(s / 60), sec(s % 60)
  {
    while (min >= MAX_MINUTE)
      min -= MAX_MINUTE;
  }
  Timer(int m, int s) : min(m), sec(s) {
    while (min >= MAX_MINUTE)
      min -= MAX_MINUTE;
  }
  Timer operator++();
  Timer operator--(int);
  friend Timer operator+ (const Timer &a, const Timer &b);
  friend ostream &operator<< (ostream &out, const Timer &foo);
};

int main()
{
  int input_1, input_2;
  Timer  foo;
  while (cin >> input_1 >> input_2)
  {
    foo = foo + input_1;
    cout << foo << endl;
    foo = input_2 + foo;
    cout << foo << endl;
    cout << ++foo << endl;
    foo = input_2;
    for (int i = input_2; i >= 0; --i)
      cout << foo-- << endl;
  }

  return 0;
}
```

> - ++x：`_type operator++();`
> - x++：`_type operator++(int);`
> - --x：`_type operator--();`
> - x--：`_type operator--(int);`

## Input

輸入有兩個正整數(單位秒)

## Output

會依照輸入換算成 `分:秒` 的格式

分別輸出

- 第一筆輸入的換算成分:秒
- 第一筆+第二筆輸入的換算成分:秒
- 第一筆+第二筆輸入+1 的換算成分:秒
- 第二筆輸入的換算成分:秒的倒數

## Sample

Input

```
200 10
```

Output

```
03 : 20
03 : 30
03 : 31
00 : 10
00 : 09
00 : 08
00 : 07
00 : 06
00 : 05
00 : 04
00 : 03
00 : 02
00 : 01
00 : 00
```
