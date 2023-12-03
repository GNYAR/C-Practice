/*
  PART 四 (15分)
    用 template counter_ptr 寫 stack LIFO
*/
#include <fstream>
#include "TemplateClass.h"

template <class T>
class stack
{
private:
  counter_ptr<T> items;
  int top, max_size;

public:
  stack() : top(0), max_size(100), items("items", new T[100]){};

  void clear()
  {
    items = new T[max_size];
    top = 0;
  }

  T pop()
  {
    return (top > 0 ? items[--top] : NULL);
  }

  void print()
  {
    for (int i = 0; i < top; i += 2)
    {
      char c[] = {items[i], items[i + 1], 0};
      cout << c;
    }
    cout << '\n';
  }

  void print_code()
  {
    for (int i = 0; i < top; i += 2)
      cout << '(' << (int)items[i] << ' ' << (int)items[i + 1] << ')' << ' ';
    cout << '\n';
  }

  void push(T x)
  {
    if (top < max_size)
      items[top++] = x;
    else
      cout << "stack is full\n";
  }
};

int main()
{
  stack<char> s;
  string line;
  ifstream file("test.txt");
  if (file.is_open())
  {
    while (getline(file, line))
    {
      switch (line[0])
      {
      case 'I':
        for (int i = 2; i < line.size(); i++)
          s.push(line[i]);
        break;
      case 'P':
        s.print();
        break;
      case 'B':
        s.print_code();
        break;
      case 'R':
        s.pop();
        s.pop();
        break;
      case 'C':
        s.clear();
        break;
      case '?':
        break;
      default:
        break;
      }
    }
    file.close();
  }
  else
    cout << "Unable to open file" << endl;

  return 0;
}
/*
1.	輸入資料為BIG5漢字(character)：
    BIG5內碼包含兩個位元組
    例子:
    我	內碼 (-89 -38)

2. 輸入資料功能：
用I開頭表示


3.	列印stack資料功能:
用P開頭表示


4.	列印stack料內碼功能:
用B開頭表示

  依照r順序將目前的資料的BIG5內碼列印出來
  例子:
  stack資料順序
  我是
  內碼列印 =>
  (-89 -38) (-84 79)

5.	拿一個資料
用R表示

6.	完全清除stack資料功能
用C表示

7. 查尋資料功能:
用?開頭表示
  查尋一個BIG5漢字是否在stack中：
  結果:	是		否


=======================================================================
test example
I 程式必須要能讀入測試檔
I 程式要徹底清除樹中資料使用的記憶體
? 程
? 體
R // 拿出最後一個    體
? 程
? 體
P
B
C
P
I 程式要徹底清除樹中資料使用的記憶體
P
B
? 讀
=======================================================================
*/
