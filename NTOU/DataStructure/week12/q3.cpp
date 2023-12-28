#include <iostream>
#include <vector>

using namespace std;

struct node
{
  int key;
  node *left, *right;
};

void insert(node *&root, int x)
{
  node *ptr = root, *parent = NULL;
  while (ptr && ptr->key != x)
  {
    parent = ptr;
    if (ptr->key < x)
      ptr = ptr->right;
    else
      ptr = ptr->left;
  }

  if (parent)
  {
    if (parent->key < x)
      parent->right = new node{x, NULL, NULL};
    else
      parent->left = new node{x, NULL, NULL};
  }
  else
    root = new node{x, NULL, NULL};
}

enum mode
{
  PREODER,
  INODER,
  POSTORDER
};

void predecessor(node *ptr, int x, mode m, int *pre)
{
  if (ptr)
  {
    switch (m)
    {
    case INODER:
      predecessor(ptr->left, x, m, pre);
      if (ptr->key == x)
        cout << *pre << ' ';
      *pre = ptr->key;
      predecessor(ptr->right, x, m, pre);
      break;
    case PREODER:
      if (ptr->key == x)
        cout << *pre << ' ';
      *pre = ptr->key;
      predecessor(ptr->left, x, m, pre);
      predecessor(ptr->right, x, m, pre);
      break;
    case POSTORDER:
      predecessor(ptr->left, x, m, pre);
      predecessor(ptr->right, x, m, pre);
      if (ptr->key == x)
        cout << *pre << ' ';
      *pre = ptr->key;
      break;
    default:
      break;
    }
  }
}

int main()
{
  node *root = NULL;
  string str;
  getline(cin, str);
  int num = 0;
  for (int i = 0; i < str.size(); i++)
  {
    if (isdigit(str[i]))
    {
      int x = str[i] - '0';
      if (num)
        num = num * 10 + x;
      else
        num = x;
    }
    else
    {
      insert(root, num);
      num = 0;
    }
  }
  insert(root, num);

  cin >> num;

  int *a = new int;
  predecessor(root, num, INODER, a);
  predecessor(root, num, PREODER, a);
  predecessor(root, num, POSTORDER, a);
  cout << '\n';
  delete a;
  return 0;
}
