#include <iostream>
#include <algorithm>
#define SIZE 50

using namespace std;

void push(string stack[], int &top, string x)
{
  stack[++top] = x;
}

string pop(string stack[], int &top)
{
  return stack[top--];
}

string parseFromPost(string post)
{
  string stack[SIZE];
  int top = -1;
  for (int i = 0; i < post.size(); i++)
  {
    if (isdigit(post[i]))
      push(stack, top, string(1, post[i]));
    else
    {
      string b = pop(stack, top), a = pop(stack, top);
      string term = '(' + a + post[i] + b + ')';
      push(stack, top, term);
    }
  }
  string str = pop(stack, top);
  str.erase(str.begin());
  str.erase(str.end() - 1);
  return str;
}

string parseFromPre(string pre)
{
  string str = pre;
  reverse(str.begin(), str.end());
  str = parseFromPost(str);
  reverse(str.begin(), str.end());
  for (int i = 0; i < str.size(); i++)
  {
    if (str[i] == '(')
      str[i] = ')';
    else if (str[i] == ')')
      str[i] = '(';
  }
  return str;
}

int main()
{
  string str;
  for (int i = 0; i < 3; i++)
  {
    cin >> str;
    if (!isdigit(str.front()))
      cout << parseFromPre(str) << endl;
    else if (!isdigit(str.back()))
      cout << parseFromPost(str) << endl;
    else
      cout << "same" << endl;
  }
  return 0;
}
