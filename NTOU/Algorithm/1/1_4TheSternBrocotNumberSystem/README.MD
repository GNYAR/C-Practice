# 1_4 The Stern-Brocot Number System

[UVa10077 - The Stern-Brocot Number System](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=1018)

## Pseudocode

觀察一下，這是一顆普通的二元搜尋樹，可以用 0/1、1/1、1/0，來產生所有符合條件的數。

這裡使用 L(初始 1/0)、M(初始 1/1)、R(初始 0/1)一組變數來產生下一組變數、直到 M 符合 F(輸入)。

運算的規則：

F > M：L = M，M = M + R

F < M：R = M，M = M + L

```
int F.numerator = input numerator, F.denominator = input denominator;
L.numerator = 0;
L.denominator = 1;
M.numerator = 1;
M.denominator = 1;
R.numerator = 1;
R.denominator = 0;
long double Fd = F.numerator / (long double)F.denominator;
long double Md = M.numerator / (long double)M.denominator;
while(!(M.denominator == F.denominator && M.numerator == F.numerator)){
  if(Fd > Md){
    L.numerator = M.numerator;
    L.denominator = M.denominator;
    M.numerator = M.numerator + R.numerator;
    M.denominator = M.denominator + R.denominator;
    print("R");
  } else {
    R.numerator = M.numerator;
    R.denominator = M.denominator;
    M.numerator = M.numerator + L.numerator;
    M.denominator = M.denominator + L.denominator;
    print("L");
  }
  Md = M.numerator / (long double)M.denominator;
}
```

## Hint

1. 輸出結尾有換行符號

## Sample

1.  Input
    ```
    5 7
    878 323
    1 1
    ```
    Output
    ```
    LRRL
    RRLRRLRLLLLRLRRR
    ```
2.  Input
    ```
    396 349
    198 83
    395 491
    563 310
    74 15
    697 401
    127 776
    342 775
    352 39
    392 69
    1 1
    ```
    Output
    ```
    RLLLLLLLRRLLRLLLLL
    RRLLRLRRLLLLL
    LRRRRLLLLLLLLRLLRL
    RLRRRRLLRRRLRLL
    RRRRLRRRRRRRRRRRRR
    RLRRLRRRRLRLLLLLLLL
    LLLLLLRRRRRRRRRLLLLLLLLLLLLL
    LLRRRLRRRLLLLLLLRR
    RRRRRRRRRLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL
    RRRRRLRRLLLLLLLRR
    ```
