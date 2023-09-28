# 1_3 The Bus Driver Problem

[UVa11389 - The Bus Driver Problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=25&page=show_problem&problem=2384)

## Pseudocode

盡量配滿每位司機的路線長度上限，就能得到最小花費。這裡使用的策略是讓早上最短的路線搭配傍晚最長的路線分配給每一位司機。

```
int n = input n, d = input d, r = input r, sum = output;
sum = 0;
int M[] = morning routes input array , E[] = evening routes input array;
sort(M);
sort(E);
for(int i =0;i<n;i++)
  if(M[i] + E[n-i-1] > d)
    sum += (M[i] + E[n-i-1] - d)\*r;
```

## Hint

1. 輸出結尾有換行符號
2. 隱藏測資有一萬組輸入

## Sample

1.  Input
    ```
    2 20 5
    10 15
    10 15
    2 20 5
    10 10
    10 10
    0 0 0
    ```
    Output
    ```
    50
    0
    ```
2.  Input
    ```
    4 6 4
    1 1 16 15
    7 10 10 12
    1 19 1
    19
    5
    2 14 5
    19 11
    8 10
    0 0 0
    ```
    Output
    ```
    192
    5
    100
    ```
