# 4_2 Graph Coloring

[UVa193 - Graph Coloring](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=129)

## Hint

1. 圖的點數需給到 300 個，並非敘述的 100 個
2. 輸入超過 80000 行
3. 請按照 字典序 輸出

## Sample

1.  Input
    ```
    1
    6 8
    1 2
    1 3
    2 4
    2 5
    3 4
    3 6
    4 6
    5 6
    ```
    Output
    ```
    3
    1 4 5
    ```
2.  Input
    ```
    3
    6 8
    1 2
    1 3
    2 4
    2 5
    3 4
    3 6
    4 6
    5 6
    2 0
    6 5
    1 2
    1 3
    2 3
    4 5
    4 6
    ```
    Output
    ```
    3
    1 4 5
    2
    1 2
    3
    1 5 6
    ```
3.  Input
    ```
    1
    16 33
    9 5
    6 4
    15 11
    13 7
    11 9
    5 12
    14 8
    1 6
    5 2
    7 9
    3 12
    6 10
    3 7
    3 8
    6 5
    1 10
    4 14
    9 13
    4 8
    13 6
    11 5
    16 15
    4 5
    13 11
    2 14
    2 16
    4 2
    14 12
    1 2
    11 16
    12 1
    15 13
    10 12
    ```
    Output
    ```
    6
    3 5 10 13 14 16
    ```
