#include <iostream>

using namespace std;

struct Node
{
  int x;
  int y;
  Node *next;
};

Node *creatNode(int x, int y);
bool isEmitted(Node *a, Node *b);
bool isGreaterThan(Node *a, Node *b);

Node *creatNode(int x, int y)
{
  Node *nPtr = (Node *)malloc(sizeof(Node));
  nPtr->x = x;
  nPtr->y = y;
  nPtr->next = NULL;
  return nPtr;
}

bool isEmitted(Node *a, Node *b)
{
  int x = abs(a->x - b->x);
  int y = abs(a->y - b->y);
  return x < 3 && y < 3;
}

bool isGreaterThan(Node *a, Node *b)
{
  return (a->y > b->y || (a->y == b->y && a->x > b->x));
}

int main()
{
  Node *head = NULL;

  int w, h, n, x, y;
  cin >> w >> h >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> x >> y;
    Node *nPtr = creatNode(x, y);
    if (head == NULL)
    {
      head = nPtr;
      continue;
    }
    Node *ptr = head, *pre = NULL;
    while (ptr != NULL && isGreaterThan(nPtr, ptr))
    {
      pre = ptr;
      ptr = ptr->next;
    }
    nPtr->next = ptr;
    if (pre == NULL)
      head = nPtr;
    else
      pre->next = nPtr;
  }

  int ans = 0;
  Node *iPtr = head;
  while (iPtr != NULL)
  {
    Node *ptr = head;
    while (ptr != iPtr && !isEmitted(iPtr, ptr))
      ptr = ptr->next;
    if (ptr == iPtr)
      ans++;
    iPtr = iPtr->next;
  }
  cout << ans << endl;
  return 0;
}
