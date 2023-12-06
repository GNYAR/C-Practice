/*
  PART 四 (15分)
    用 template counter_ptr 寫 stack LIFO
*/
#include <fstream>
#include "3_1_TemplateClass.h" // 引入 template class

// 以字元陣列存放 BIG5 漢字，每一個漢字佔兩個字元空間，最大容納為 50 個漢字 (MAX / 2)
#define MAX 100

class stack
{
private:
  counter_ptr<char> items; // 指向字元陣列的指標
  int top;                 // top 記錄目前 stack 的頂端索引

public:
  // 建立 stack，初始化 top，並動態配置陣列
  stack() : top(0), items("items", new char[MAX]){};

  // 清空 stack
  void clear()
  {
    items = new char[MAX]; // 配置全新位置，counter_ptr 會自動釋放舊資料
    top = 0;               // 初始化 top
  }

  // 刪除最後一個漢字
  void pop()
  {
    if (top) // 若 stack 不為空
    {
      top -= 2; // 刪除頂端一個漢字
      // 印出被刪除的漢字
      char x[] = {items[top], items[top + 1], 0};
      cout << "stack pop " << x << '\n';
    }
  }

  // 依序印出 stack 所有漢字
  void print()
  {
    for (int i = 0; i < top; i += 2)
    { // 依序將兩個字元組合成一個漢字並印出
      char c[] = {items[i], items[i + 1], 0};
      cout << c;
    }
    cout << '\n';
  }

  // 以整數型態依序印出 stack 所有字元
  void print_code()
  {
    for (int i = 0; i < top; i += 2) // 依序將兩個字元以整數型態印出
      cout << '(' << (int)items[i] << ' ' << (int)items[i + 1] << ')' << ' ';
    cout << '\n';
  }

  // 將漢字新增至 stack
  void push(char x[])
  {
    if (top + 1 < MAX) // 確認足夠放進一個漢字
    {                  // 依序加入代表漢字的兩個字元
      items[top++] = x[0];
      items[top++] = x[1];
    }
    else
      cout << "stack is full\n";
  }

  // 檢查漢字是否已存在 stack
  bool includes(char x[])
  {
    for (int i = 0; i < top; i += 2)
    { // 兩個字元一組依序檢查，若符合傳入的漢字則回傳
      if (items[i] == x[0] && items[i + 1] == x[1])
        return true;
    }
    return false;
  }
};

int main()
{
  // 輸入資料為 BIG5 漢字(character)：
  //  BIG5 內碼包含兩個位元組
  //  例子: 我   內碼 (-89 -38)

  stack s;
  int i;           // 記錄讀入字串的索引
  char x[3] = {0}; // 記錄讀入的漢字

  // 輸入檔 test.txt 為 BIG5 編碼的文字檔
  string line;               // 記錄讀入的指令
  ifstream file("test.txt"); // 開啟輸入檔

  if (file.is_open()) // 確認檔案是否開啟成功
  {
    while (getline(file, line)) // 依序將讀取每一行輸入指令
    {
      switch (line[0]) // 檢查指令功能
      {
      // 輸入資料功能：用 I 開頭表示
      case 'I':
        i = 2; // 依序讀入指令的漢字，並新增到 stack
        while (i < line.size())
        {
          x[0] = line[i++];
          x[1] = line[i++];
          s.push(x);
        }
        break;

      // 列印 stack 資料功能: 用 P 表示
      case 'P':
        s.print(); // 依序印出 stack 所有漢字
        break;

      // 列印stack料內碼功能: 用 B 表示
      // 依照 r 順序將目前的資料的 BIG5 內碼列印出來
      // 例子: 我是   內碼列印 => (-89 -38) (-84 79)
      case 'B':
        s.print_code(); // 以整數型態依序印出 stack 所有字元
        break;

      // 拿出最後一個資料: 用 R 表示
      case 'R':
        s.pop(); // 刪除最後一個漢字
        break;

      // 完全清除stack資料功能: 用 C 表示
      case 'C':
        s.clear(); // 清空 stack
        break;

      // 查尋資料功能: 用 ? 開頭表示
      // 查尋一個BIG5漢字是否在 stack 中
      // 結果: Yes/No
      case '?':
        // 讀入指令的漢字
        x[0] = line[2];
        x[1] = line[3];
        // 印出是否漢字已存在 stack
        cout << (s.includes(x) ? "Yes" : "No") << '\n';
        break;
      default:
        break;
      }
    }
    file.close(); // 關閉檔案
  }
  else
    cout << "Unable to open file" << endl;

  return 0;
}
