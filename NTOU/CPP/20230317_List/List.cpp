#include <iostream>
#include <cstring>
#define MAX_INPUT_LENGTH 25

using namespace std;

struct Node
{
  char *item;
  Node *next;
};

Node *creatNode(char item[MAX_INPUT_LENGTH]);

Node *creatNode(char item[MAX_INPUT_LENGTH])
{
  Node *nPtr = (Node *)malloc(sizeof(Node));
  nPtr->item = (char *)malloc(sizeof(char[MAX_INPUT_LENGTH]));
  strcpy(nPtr->item, item);
  nPtr->next = NULL;
  return nPtr;
}

int main()
{
  Node *head = NULL, *tail = NULL;

  char *d = " ";
  char input[MAX_INPUT_LENGTH];
  while (cin.getline(input, MAX_INPUT_LENGTH))
  {
    if (!(input[0]))
      continue;

    char arg[3][MAX_INPUT_LENGTH], *p;
    int i = 0;
    p = strtok(input, d);
    while (p != NULL)
    {
      strcpy(arg[i++], p);
      p = strtok(NULL, d);
    };

    if (!strcmp(arg[0], "ADD"))
    { // 1: ADD
      Node *nPtr = creatNode(arg[1]);
      if (head == NULL)
      {
        head = nPtr;
        tail = nPtr;
      }
      else
      {
        tail->next = nPtr;
        tail = nPtr;
      }
    }
    else if (!strcmp(arg[0], "INSERT"))
    { // 2: INSERT
      Node *ptr = head, *pre = NULL;
      while (ptr != NULL && strcmp(ptr->item, arg[2]))
      {
        pre = ptr;
        ptr = ptr->next;
      }

      Node *nPtr = creatNode(arg[1]);
      nPtr->next = ptr;
      if (pre == NULL)
        head = nPtr;
      else
        pre->next = nPtr;
    }
    else if (!strcmp(arg[0], "REMOVE"))
    { // 3: REMOVE
      Node *ptr = head, *pre = NULL;
      while (ptr != NULL && strcmp(ptr->item, arg[1]))
      {
        pre = ptr;
        ptr = ptr->next;
      }

      if (pre == NULL)
        head = ptr->next;
      else
        pre->next = ptr->next;
      free(ptr);
    }
    else if (!strcmp(arg[0], "SHOW"))
    { // 4: SHOW
      Node *ptr = head;
      while (ptr != NULL)
      {
        cout << ptr->item;
        ptr = ptr->next;
        if (ptr == NULL)
          cout << endl;
        else
          cout << ' ';
      }
      break;
    }
  }
  return 0;
}
