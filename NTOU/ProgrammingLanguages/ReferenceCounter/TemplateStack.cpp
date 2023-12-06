/*
  PART 四 (15分)
    用 template counter_ptr 寫 stack LIFO
*/
#include <fstream>
#include "TemplateClass.h"
#define MAX 100

class stack
{
private:
  counter_ptr<char> items;
  int top, max_size;

public:
  stack() : top(0), max_size(MAX), items("items", new char[MAX]){};

  void clear()
  {
    items = new char[max_size];
    top = 0;
  }

  void pop()
  {
    if (top > 0)
    {
      top -= 2;
      char x[] = {items[top], items[top + 1], 0};
      cout << "stack pop " << x << '\n';
    }
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

  void push(char x[])
  {
    if (top + 1 < max_size)
    {
      items[top++] = x[0];
      items[top++] = x[1];
    }
    else
      cout << "stack is full\n";
  }

  bool includes(char x[])
  {
    for (int i = 0; i < top; i += 2)
    {
      if (items[i] == x[0] && items[i + 1] == x[1])
        return true;
    }
    return false;
  }
};

int main()
{
  {
    stack s;
    int i;
    char x[2];

    // 輸入資料為 BIG5 漢字(character)：
    //  BIG5 內碼包含兩個位元組
    //  例子: 我   內碼 (-89 -38)

    // 輸入檔 test.txt 為 BIG5 編碼的文字檔
    string line;
    ifstream file("test.txt");
    if (file.is_open())
    {
      while (getline(file, line))
      {
        switch (line[0])
        {
        // 輸入資料功能：用 I 開頭表示
        case 'I':
          i = 2;
          while (i < line.size())
          {
            x[0] = line[i++];
            x[1] = line[i++];
            s.push(x);
          }
          break;

        // 列印 stack 資料功能: 用 P 表示
        case 'P':
          s.print();
          break;

        // 列印stack料內碼功能: 用 B 表示
        // 依照 r 順序將目前的資料的 BIG5 內碼列印出來
        // 例子: 我是   內碼列印 => (-89 -38) (-84 79)
        case 'B':
          s.print_code();
          break;

        // 拿出最後一個資料: 用 R 表示
        case 'R':
          s.pop();
          break;

        // 完全清除stack資料功能: 用 C 表示
        case 'C':
          s.clear();
          break;

        // 查尋資料功能: 用 ? 開頭表示
        // 查尋一個BIG5漢字是否在 stack 中
        // 結果: 是/否
        case '?':
          x[0] = line[2];
          x[1] = line[3];
          cout << (s.includes(x) ? "是" : "否") << '\n';
          break;
        default:
          break;
        }
      }
      file.close();
    }
    else
      cout << "Unable to open file" << endl;
  }

  system("pause");
  return 0;
}
