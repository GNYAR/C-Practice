/*
  PART 三 (15分)
    2) 重覆 PART 一  二 的測試
*/
#include "TemplateClass.h"

int main()
{

  // PART 一  (35分)

  counter_ptr<int> b("b", new int[10]);
  // 需要撰寫 counter_ptr constructor(建構子) 接受兩個參數
  // stdout 輸出: int_array_cell is allocated
  // stdout 輸出: counter_ptr b is assigned to an int_array_cell: counter 1

  {
    b = new int[100];
    // 需要撰寫 counter_ptr operator=
    // stdout 輸出: int_array_cell counter 0: deleted
    // stdout 輸出: int_array_cell is allocated
    // stdout 輸出: counter_ptr b is assigned to an int_array_cell: counter 1

    counter_ptr<int> a("a");
    // 需要撰寫 counter_ptr constructor(建構子) 接受一個參數
    // stdout 輸出: counter_ptr a is not assigned to an int_array_cell

    a = b;
    // 需要撰寫 counter_ptr operator=
    // stdout 輸出: int_array_cell counter is increased: counter 2
    // stdout 輸出: counter_ptr a is assigned to an int_array_cell: counter 2
  }
  // a leaves it scope:
  // 需要撰寫 counter_ptr destructor
  // stdout 輸出: counter_ptr a is deleted
  // stdout 輸出: int_array_cell counter is decreased: counter 1

  // PART 二  (35分)

  for (int i = 0; i < 10; i++)
    b[i] = i;
  // 需要撰寫 counter_ptr operator[] 寫值(回傳資料的參考 return type: int &)

  for (int i = 0; i < 10; i++)
    cout << b[i] << ' '; // 需要撰寫 counter_ptr operator[] 讀值(回傳資料)
  cout << endl;
  // stdout 輸出: 0 1 2 3 4 5 6 7 8 9

  counter_ptr<int> c("c");
  // stdout 輸出: counter_ptr c is not assigned to an int_array_cell

  c = b;
  // stdout 輸出: int_array_cell counter is increased: counter 2
  // stdout 輸出: counter_ptr c is assigned to an int_array_cell: counter 2

  b.release();
  // 需要撰寫 counter_ptr release function: 不使用記憶體
  // stdout 輸出: int_array_cell counter is decreased: counter 1
  // stdout 輸出: counter_ptr b is not assigned to an int_array_cell

  return 0;
}
// c leaves it scope:	//需要撰寫 counter_ptr destructor
// stdout 輸出: counter_ptr c is deleted
// stdout 輸出: int_array_cell counter 0: deleted
// stdout 輸出: counter_ptr b is deleted