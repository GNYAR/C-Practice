# Combination

請遞迴函式 計算組合數 C(n,k)

其中 0 ≤ k ≤ n ≤ 33, 由於在遞迴的過程中 計算組合數遞迴函式 會用相同的參數呼叫不只一次，例如計算組合數 C(5,3) = C(4,2) + C(4,1) = C(3,2) + C(3,1) + C(3,1) + C(3,0) = ...

如果每一個都呼叫的話其實會很浪費 CPU 時間，請定義一個二維陣列 R[34][34] 來記錄計算出來的 C(n,k)

在遞迴的過程中當作函式參數傳遞，每次需要計算 C(n,k)時先檢查 R[n][k] 來確定是否曾經計算過。如果沒有算過才實際計算，算出來以後把結果存放在陣列 R[n][k] 中。

## Input

每一列先是兩個整數 n 及 k，計算 C(n, k)

接下來兩個整數 n1 及 k1 是想要知道遞迴函式在參數為 n1，k1 時被呼叫了幾次， 串流結束代表資料結束。

## Output

對每一列輸入的兩個整數 n 及 k，輸出 C(n,k)，接下來輸出遞迴函式在參數為 n1，k1 時被呼叫到的次數，例如：第五筆測資 26 13 7 4，輸出 10400600 2 92378，代表遞迴計算 C(26,13) 時結果是 10400600，過程中 func() 函式以參數為 (7，4) 時被呼叫了 2 次，92378 則是沒有記憶時遞迴函式以參數為 (7, 4) 時被呼叫的次數，n < k 時請輸出 "error"，請注意遞迴函式被呼叫的次數和遞迴函式的結束條件有關，這個題目裡請在 n==k 或是 k==0 時結束遞迴函式。

## Sample

Input

```
5 2 1 1
32 1 3 2
33 28 4 2
10 15 1 1
26 13 7 4
```

Output

```
10 1 3
32 0 0
237336 2 3654
error
10400600 2 92378
```
