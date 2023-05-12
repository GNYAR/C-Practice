#include <iostream>
#include <stack> // 引入 C++ STL (標準模板函式庫) 中的 stack 樣板類別
#include <string>

using namespace std;

bool isValid(string s)
{
  stack<char> st; // 建立 stack 來儲存開括號

  // 依序檢查每個字符
  for (char c : s)
  {
    if (c == '(' || c == '[' || c == '{')
    {             // 如果是開括號
      st.push(c); // 將其壓入 stack 中
    }
    else if (c == ')')
    { // 如果是閉括號 )
      if (st.empty() || st.top() != '(')
      {               // 如果 stack 為空或者不符合開括號 (
        return false; // 回傳 false
      }
      else
      {
        st.pop(); // 否則將 stack 中的開括號 ( 彈出
      }
    }
    else if (c == ']')
    { // 如果是閉括號 ]
      if (st.empty() || st.top() != '[')
      {               // 如果 stack 為空或者不符合開括號 [
        return false; // 回傳 false
      }
      else
      {
        st.pop(); // 否則將 stack 中的開括號 [ 彈出
      }
    }
    else if (c == '}')
    { // 如果是閉括號 }
      if (st.empty() || st.top() != '{')
      {               // 如果 stack 為空或者不符合開括號 {
        return false; // 回傳 false
      }
      else
      {
        st.pop(); // 否則將 stack 中的開括號 { 彈出
      }
    }
  }

  // 如果最後 stack 是空的，表示所有括號都已經匹配完畢，回傳 true，否則回傳 false
  return st.empty();
}

int main()
{
  string s;
  while (getline(cin, s))
  {                                          // 不斷讀入輸入
    s = s.substr(1, s.size() - 2);           // 刪除首尾的引號
    cout << boolalpha << isValid(s) << endl; // 輸出檢查結果
  }
  return 0;
}