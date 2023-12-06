/*
  PART �| (15��)
    �� template counter_ptr �g stack LIFO
*/
#include <fstream>
#include "3_1_TemplateClass.h" // �ޤJ template class

// �H�r���}�C�s�� BIG5 �~�r�A�C�@�Ӻ~�r����Ӧr���Ŷ��A�̤j�e�Ǭ� 50 �Ӻ~�r (MAX / 2)
#define MAX 100

class stack
{
private:
  counter_ptr<char> items; // ���V�r���}�C������
  int top;                 // top �O���ثe stack �����ݯ���

public:
  // �إ� stack�A��l�� top�A�ðʺA�t�m�}�C
  stack() : top(0), items("items", new char[MAX]){};

  // �M�� stack
  void clear()
  {
    items = new char[MAX]; // �t�m���s��m�Acounter_ptr �|�۰������¸��
    top = 0;               // ��l�� top
  }

  // �R���̫�@�Ӻ~�r
  void pop()
  {
    if (top) // �Y stack ������
    {
      top -= 2; // �R�����ݤ@�Ӻ~�r
      // �L�X�Q�R�����~�r
      char x[] = {items[top], items[top + 1], 0};
      cout << "���X�̫�@��\t" << x << '\n';
    }
  }

  // �̧ǦL�X stack �Ҧ��~�r
  void print()
  {
    for (int i = 0; i < top; i += 2)
    { // �̧ǱN��Ӧr���զX���@�Ӻ~�r�æL�X
      char c[] = {items[i], items[i + 1], 0};
      cout << c;
    }
    cout << '\n';
  }

  // �H��ƫ��A�̧ǦL�X stack �Ҧ��r��
  void print_code()
  {
    for (int i = 0; i < top; i += 2) // �̧ǱN��Ӧr���H��ƫ��A�L�X
      cout << '(' << (int)items[i] << ' ' << (int)items[i + 1] << ')' << ' ';
    cout << '\n';
  }

  // �N�~�r�s�W�� stack
  void push(char x[])
  {
    if (top + 1 < MAX) // �T�{������i�@�Ӻ~�r
    { // �̧ǥ[�J�N��~�r����Ӧr��
      items[top++] = x[0];
      items[top++] = x[1];
    }
    else
      cout << "stack is full\n";
  }

  // �ˬd�~�r�O�_�w�s�b stack
  bool includes(char x[])
  {
    for (int i = 0; i < top; i += 2)
    { // ��Ӧr���@�ը̧��ˬd�A�Y�ŦX�ǤJ���~�r�h�^��
      if (items[i] == x[0] && items[i + 1] == x[1])
        return true;
    }
    return false;
  }
};

int main()
{
  // ��J��Ƭ� BIG5 �~�r(character)�G
  //  BIG5 ���X�]�t��Ӧ줸��
  //  �Ҥl: ��   ���X (-89 -38)

  stack s;
  int i;     // �O��Ū�J�r�ꪺ����
  char x[2]; // �O��Ū�J���~�r

  // ��J�� test.txt �� BIG5 �s�X����r��
  string line; // �O��Ū�J�����O
  ifstream file("test.txt"); // �}�ҿ�J��
  if (file.is_open()) // �T�{�ɮ׫ǧ_�}�Ҧ��\
  {
    while (getline(file, line)) // �̧ǱNŪ���C�@���J���O
    {
      switch (line[0]) // �ˬd���O�\��
      {
      // ��J��ƥ\��G�� I �}�Y���
      case 'I':
        i = 2; // �̧�Ū�J���O���~�r�A�÷s�W�� stack
        while (i < line.size())
        {
          x[0] = line[i++];
          x[1] = line[i++];
          s.push(x);
        }
        break;

      // �C�L stack ��ƥ\��: �� P ���
      case 'P':
        s.print(); // �̧ǦL�X stack �Ҧ��~�r
        break;

      // �C�Lstack�Ƥ��X�\��: �� B ���
      // �̷� r ���ǱN�ثe����ƪ� BIG5 ���X�C�L�X��
      // �Ҥl: �ڬO   ���X�C�L => (-89 -38) (-84 79)
      case 'B':
        s.print_code(); // �H��ƫ��A�̧ǦL�X stack �Ҧ��r��
        break;

      // ���X�̫�@�Ӹ��: �� R ���
      case 'R':
        s.pop(); // �R���̫�@�Ӻ~�r
        break;

      // �����M��stack��ƥ\��: �� C ���
      case 'C':
        s.clear(); // �M�� stack
        break;

      // �d�M��ƥ\��: �� ? �}�Y���
      // �d�M�@��BIG5�~�r�O�_�b stack ��
      // ���G: �O/�_
      case '?':
        // Ū�J���O���~�r
        x[0] = line[2];
        x[1] = line[3];
        // �L�X�O�_�~�r�w�s�b stack
        cout << (s.includes(x) ? "�O" : "�_") << '\n';
        break;
      default:
        break;
      }
    }
    file.close(); // �����ɮ�
  }
  else
    cout << "Unable to open file" << endl;

  return 0;
}
