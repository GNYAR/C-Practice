#include <iostream>

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

void remove(node *root, int x)
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

  if (ptr)
  {
    if (ptr->left && ptr->right)
    {
      parent = ptr;
      node *sub = ptr->left;
      while (sub && sub->right)
      {
        parent = sub;
        sub = sub->right;
      }
      ptr->key = sub->key;
      if (parent == ptr)
        ptr->left = sub->left;
      else
        parent->right = sub->left;
      delete sub;
    }
    else
    {
      node *sub = ptr->left ? ptr->left : ptr->right;
      if (sub)
      {
        *ptr = *sub;
        delete sub;
      }
      else
      {
        if (parent->left == ptr)
          parent->left = NULL;
        else
          parent->right = NULL;
        delete ptr;
      }
    }
  }
  else
    cout << "no " << x << '\n';
}

void print(node *ptr)
{
  if (ptr)
  {
    cout << ptr->key << ' ';
    print(ptr->left);
    print(ptr->right);
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
  cout << "Binary search tree (before):\n";
  print(root);
  cout << '\n';

  getline(cin, str);
  num = 0;
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
      remove(root, num);
      num = 0;
    }
  }
  remove(root, num);
  cout << "Binary search tree (after):\n";
  print(root);
  cout << '\n';

  return 0;
}
