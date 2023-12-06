/*
  PART �| (15��)
    �� template counter_ptr �g stack LIFO
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

    // ��J��Ƭ� BIG5 �~�r(character)�G
    //  BIG5 ���X�]�t��Ӧ줸��
    //  �Ҥl: ��   ���X (-89 -38)

    // ��J�� test.txt �� BIG5 �s�X����r��
    string line;
    ifstream file("test.txt");
    if (file.is_open())
    {
      while (getline(file, line))
      {
        switch (line[0])
        {
        // ��J��ƥ\��G�� I �}�Y���
        case 'I':
          i = 2;
          while (i < line.size())
          {
            x[0] = line[i++];
            x[1] = line[i++];
            s.push(x);
          }
          break;

        // �C�L stack ��ƥ\��: �� P ���
        case 'P':
          s.print();
          break;

        // �C�Lstack�Ƥ��X�\��: �� B ���
        // �̷� r ���ǱN�ثe����ƪ� BIG5 ���X�C�L�X��
        // �Ҥl: �ڬO   ���X�C�L => (-89 -38) (-84 79)
        case 'B':
          s.print_code();
          break;

        // ���X�̫�@�Ӹ��: �� R ���
        case 'R':
          s.pop();
          break;

        // �����M��stack��ƥ\��: �� C ���
        case 'C':
          s.clear();
          break;

        // �d�M��ƥ\��: �� ? �}�Y���
        // �d�M�@��BIG5�~�r�O�_�b stack ��
        // ���G: �O/�_
        case '?':
          x[0] = line[2];
          x[1] = line[3];
          cout << (s.includes(x) ? "�O" : "�_") << '\n';
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
