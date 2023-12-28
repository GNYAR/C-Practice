#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct item
{
  string name;
  vector<int> prices;
  item *link;
};

void insert(item *&head, string name, int price)
{
  if (head)
  {

    item *ptr = head, *pre = NULL;
    while (ptr && ptr->name != name)
    {
      pre = ptr;
      ptr = ptr->link;
    }
    if (ptr)
    {
      ptr->prices.push_back(price);
      return;
    }
    item *x = new item{name, {price}, NULL};
    pre->link = x;
    return;
  }
  item *x = new item{name, {price}, NULL};
  head = x;
}

int main()
{
  int n, price;
  item *head = NULL;
  string name;
  cin >> n;
  while (n--)
  {
    cin >> name >> price;
    insert(head, name, price);
  }
  for (item *ptr = head; ptr; ptr = ptr->link)
  {
    sort(ptr->prices.begin(), ptr->prices.end());
    cout << ptr->name << ',';
    for (int i = 0; i < ptr->prices.size(); i++)
      cout << ptr->prices[i] << ',';
    cout << endl;
  }

  for (item *ptr = head->link; ptr; ptr = ptr->link)
  {
    delete head;
    head = ptr;
  }
  delete head;
  return 0;
}
