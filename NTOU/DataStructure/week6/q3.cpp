#include <iostream>
#include <cmath>
#define SIZE 50

using namespace std;

void push(int stack[], int &top, int x)
{
  stack[++top] = x;
}

int pop(int stack[], int &top)
{
  return stack[top--];
}

int main()
{
  int stack[SIZE], top = -1, a, b;
  char c;
  string numStr = "";
  while (cin.get(c))
  {
    switch (c)
    {
    case '+':
      b = pop(stack, top);
      a = pop(stack, top);
      push(stack, top, a + b);
      break;
    case '-':
      b = pop(stack, top);
      a = pop(stack, top);
      push(stack, top, a - b);
      break;
    case '*':
      b = pop(stack, top);
      a = pop(stack, top);
      push(stack, top, a * b);
      break;
    case '/':
      b = pop(stack, top);
      a = pop(stack, top);
      push(stack, top, a / b);
      break;
    case '%':
      b = pop(stack, top);
      a = pop(stack, top);
      push(stack, top, a % b);
      break;
    case ' ':
      if (numStr.size())
      {
        int x = 0, exp = numStr.size() - 1;
        for (int i = 0; i < numStr.size(); i++)
          x += (numStr[i] - '0') * pow(10, exp--);
        push(stack, top, x);
        numStr = "";
      }
      break;
    default:
      if (isdigit(c))
        numStr += c;
      break;
    }
  }
  cout << pop(stack, top) << endl;

  return 0;
}
