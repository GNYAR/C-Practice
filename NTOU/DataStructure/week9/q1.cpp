#include <iostream>

using namespace std;

struct item
{
  string str;
  int count;
  item *link;
};

string toLower(string str)
{
  for (int i = 0; i < str.size(); i++)
    str[i] = tolower(str[i]);
  return str;
}

item *search(item *head, string str)
{
  item *ptr = head;

  while (ptr && toLower(ptr->str) != toLower(str))
    ptr = ptr->link;
  return ptr;
}

void insert(item *&head, string str, int index)
{
  if (head)
  {
    item *ptr = search(head, str);
    if (ptr)
    {
      ptr->count++;
      return;
    }

    ptr = head;
    if (index == NULL)
    {
      while (ptr->link)
        ptr = ptr->link;
    }
    else
    {
      int i;
      for (i = 1; i < index && ptr->link; i++)
        ptr = ptr->link;
      if (i != index)
        return;
    }
    item *x = new item{str, 1, ptr->link};
    ptr->link = x;
    return;
  }
  item *x = new item{str, 1, NULL};
  head = x;
}

void print(item *head)
{
  for (item *ptr = head; ptr; ptr = ptr->link)
    cout << ptr->str << ", " << ptr->count << endl;
}

int main()
{
  item *head = NULL;
  string str;
  cin >> str;
  while (str != "#Finish")
  {
    insert(head, str, NULL);
    cin >> str;
  }
  cin >> str;
  while (str != "#Exit")
  {
    if (str == "#Insert")
    {
      int i;
      cin >> i >> str;
      insert(head, str, i);
    }
    else if (str == "#Add")
    {
      cin >> str;
      insert(head, str, NULL);
    }
    else if (str == "#Print")
    {
      print(head);
    }
    cin >> str;
  }

  for (item *ptr = head->link; ptr; ptr = ptr->link)
  {
    delete head;
    head = ptr;
  }
  delete head;
  return 0;
}
