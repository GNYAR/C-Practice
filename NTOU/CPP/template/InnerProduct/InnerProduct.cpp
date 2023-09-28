#include <iostream>
#include <vector>
#include <list>
#include <iomanip>

using namespace std;

template <typename T>
struct Abs
{
  T operator()(const T &n) { return abs(n); }
};

template <typename T, typename Iter1, typename Iter2, typename U>
T inner_product(Iter1 start_a, Iter1 end_a, Iter2 start_b, T init, U fn)
{
  while (start_a != end_a)
    init += fn(*start_a++) * fn(*start_b++);
  return init;
}

int main()
{ // 請勿更動main()函式的程式碼

  vector<int> a;
  list<int> b;
  int input, sum = 0;

  cin >> input; // 將元素輸入至容器vector,list中
  for (int i = 0; i < input; i++)
  {
    int element;
    cin >> element;
    a.push_back(element);
  }
  for (int i = 0; i < input; i++)
  {
    int element;
    cin >> element;
    b.push_back(element);
  }
  // 輸出兩個容器元素的絕對值乘積和
  cout << "The absolute inner product of a and b = "
       << inner_product(a.begin(), a.end(),
                        b.begin(), sum, Abs<int>())
       << endl;
  // Abs<int>()可看成Abs結構/類別中的運算子()覆載
  return 0;
}
