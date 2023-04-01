#include <iostream>

using namespace std;

struct Item
{
  int position, speed, cnt;
  Item *next;
};

void clear(Item **head, Item **tail);
void push(Item **head, Item **tail, Item item);
Item shift(Item **head, Item **tail);

void clear(Item **head, Item **tail)
{
  while (*head != NULL)
  {
    Item *ptr = *head;
    *head = ptr->next;
    delete ptr;
  }
  *tail = NULL;
}

void push(Item **head, Item **tail, Item item)
{
  Item *ptr = new Item(item);
  ptr->next = NULL;
  if (*head == NULL)
    *head = ptr;
  else
    (*tail)->next = ptr;
  *tail = ptr;
}

Item shift(Item **head, Item **tail)
{
  Item item = **head, *ptr = *head;
  *head = item.next;
  if (*head == NULL)
    tail = NULL;
  delete ptr;
  return item;
}

int main()
{
  int n;
  while (cin >> n && n)
  {
    Item *ptr = new Item;
    // [根節點] { position: 0, speed: 1, cnt: 0 }
    ptr->position = 0;
    ptr->speed = 1;
    ptr->cnt = 0;
    ptr->next = NULL;
    // Queue (linked-list)
    Item *head = ptr, *tail = ptr;

    while (head != NULL)
    {
      // BFS
      Item item = shift(&head, &tail);
      if (item.position == n)
      {
        cout << item.cnt << endl;
        clear(&head, &tail); // free the memory of the queue
        break;
      }

      // 避免產生不必要的節點，超過目標的兩倍就停止 (等比級數)
      if (abs(item.position) > 2 * n)
        continue;

      // [左子樹] 繼續往前
      Item newItem = item;
      newItem.position += item.speed;
      newItem.speed *= 2;
      newItem.cnt += 1;
      push(&head, &tail, newItem);

      // [右子樹] 若下一步會離目標更遠或經過目標, 則轉向 (走下一步後目標在後方)
      if ((item.position + item.speed > n && item.speed > 0) || (item.position + item.speed < n && item.speed < 0))
      {
        newItem = item;
        newItem.speed = item.speed > 0 ? -1 : 1;
        newItem.cnt += 1;
        push(&head, &tail, newItem);
      }
    }
  }

  return 0;
}
