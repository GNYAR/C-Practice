# 1_1 Longest Increasing Subsequence

給定一個未排序的整數陣列，請算出最長遞增序列的長度。

例如：輸入整數陣列 `[10, 9, 2, 5, 3, 7, 101, 18]`，則最長遞增序列為 `[2, 3, 7, 101]`。

請設計一個 `O(nlogn)` 的演算法解決這個問題。

[解題說明](https://docs.google.com/presentation/d/1_YhL1LqPdaVCechYmk9uFy98dLawfa6x5f5O8eSTz6g/edit?usp=sharing)

## Input

第一個整數 n 代表整數陣列的長度。接著有 n 個整數 a1 , a2 , ... , an，代表整數陣列的內容

- 1 <= n <= 10^6
- 1 <= ai <= n for all 1 <= i <= n

## Output

請輸出一個整數，代表最長遞增序列的長度

## Sample

1.  Input
    ```
    10
    6 7 3 7 10 8 6 1 8 10
    ```
    Output
    ```
    4
    ```
2.  Input
    ```
    20
    3 11 16 1 18 7 5 12 20 10 16 3 3 3 5 4 20 14 5 4
    ```
    Output
    ```
    5
    ```
