#include <iostream>
#include <cmath>

using namespace std;

template <typename T>
T sum(const T arr[], const T &s, const T &v)
{
  T i = s, a = v;
  while (i--)
    a += arr[i];

  return a;
}

template <typename T>
T abs_sum(const T arr[], const T &s, const T &v)
{
  T i = s, a = v;
  while (i--)
    a += abs(arr[i]);

  return a;
}

template <typename T>
T product(const T arr[], const T &s, const T &v)
{
  T i = s, a = v;
  while (i--)
    a *= arr[i];

  return a;
}

template <typename T, typename U>
T compute(const U func, const T arr[], const T &s, const T &v)
{
  return func(arr, s, v);
}

int main()
{ // 請勿更動main()函式裡的程式碼
  int foo[10];
  int S;

  cin >> S;

  for (int i = 0; i < S; i++)
    cin >> foo[i];
  int v;

  v = 0;
  cout << compute(sum<int>, foo, S, v) << endl;

  v = 0;
  cout << compute(abs_sum<int>, foo, S, v) << endl;

  v = 1;
  cout << compute(product<int>, foo, S, v) << endl;

  return 0;
}