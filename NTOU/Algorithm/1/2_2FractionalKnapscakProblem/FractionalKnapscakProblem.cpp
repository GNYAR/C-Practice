#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

struct Item
{
  int value, weight;
  double key;
};

bool compare(Item, Item);

bool compare(Item a, Item b)
{
  return a.key > b.key;
}

int main()
{
  int c;
  Item item;
  vector<Item> items;
  cin >> c;
  while (cin >> item.value >> item.weight)
  {
    item.key = (double)item.value / item.weight;
    items.push_back(item);
  }
  sort(items.begin(), items.end(), compare);

  int load = 0, i = 0;
  double value = 0;
  while (load < c && i < items.size())
  {
    item = items[i];
    int r = c - load;
    bool isEnough = item.weight <= r;

    load += isEnough ? item.weight : r;
    value += isEnough ? item.value : item.key * r;

    i++;
  }
  cout << fixed << setprecision(6) << value << endl;

  return 0;
}
