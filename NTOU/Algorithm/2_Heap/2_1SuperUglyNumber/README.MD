# 2_1 Super Ugly Number

給定一個嚴格遞增質數陣列，若一個整數的質因數皆為此陣列中的元素，我們稱之為 super ugly number。請找出由小到大第 n 個 super ugly number。例如：輸入質數陣列 `[2, 7, 13, 19]`，則前 10 個 super ugly number 為 `[1, 2, 4, 7, 8, 13, 14, 16, 19, 26]`。

## Input

第一個整數 `n` 代表 super ugly number 的序號。第二個整數 `k` 代表質數陣列的長度。接著有 k 個整數 `a1, a2, ... ,ak`，代表質數陣列的內容。

- 1 ≤ n ≤ 106
- 1 ≤ k ≤ 100
- 1 ≤ ai ≤ 1000 for all 1 ≤ i ≤ k

## Output

請輸出一個整數，代表第 n 個 super ugly number。

## Sample

1.  Input
    ```
    10 5
    17 29 31 73 79
    ```
    Output
    ```
    841
    ```
2.  Input
    ```
    20 5
    7 11 41 43 97
    ```
    Output
    ```
    1681
    ```
