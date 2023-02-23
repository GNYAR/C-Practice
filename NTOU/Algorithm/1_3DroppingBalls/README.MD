# 1_3 Dropping Balls

[UVa679 - Dropping Balls](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=8&page=show_problem&problem=620)

## Pseudocode

請試著切割原問題，例如 dep(N) 的樹能分成 dep(N-1) x2 + root，而球從 root 落下時會根據是第幾顆球來決定往左或往右（奇數往左，偶數往右），落下後第幾顆球變更為 N/2 或 N/2+1。因此可以利用第幾顆球來求出最後落下的位置。

```
int nball = input nth ball, dep = input depth, pos = output, j;
pos = 1,j = 1;
while(j &lt dep) {
  if(nball %2 == 0)
    pos = pos*2 + 1;
  else
    pos = pos*2;
  if(nball > 1) {
    if(nball %2 == 0)
      nball = nball / 2;
    else
      nball = nball / 2 + 1;
  }
  j++;
}
```

## Hint

1. 輸出結尾有換行符號
