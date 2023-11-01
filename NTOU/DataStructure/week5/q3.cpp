#include <iostream>
#define NUM 5

using namespace std;

typedef struct
{
  char id;
  float value, weight;
} item;

void push(item stack[], int *top, item x)
{
  stack[++(*top)] = x;
}

void pushInBag(item stack[], int *top, float *weight, item x)
{
  push(stack, top, x);
  *weight += x.weight;
}

item pop(item stack[], int *top)
{
  return stack[(*top)--];
}

int main()
{
  item bag[NUM], temp[NUM], x;
  int bagTop = -1, tempTop = -1;
  float bagWeight = 0;
  for (int i = 0; i < NUM; i++)
  {
    cin >> x.id >> x.value >> x.weight;
    if (bagWeight + x.weight <= 20)
    {
      pushInBag(bag, &bagTop, &bagWeight, x);
      continue;
    }

    while (bagTop > -1)
    {
      item y = pop(bag, &bagTop);
      bagWeight -= y.weight;
      if (x.value > y.value && bagWeight + x.weight <= 20)
        break;
      push(temp, &tempTop, y);
    }

    while (tempTop > -1)
    {
      item y = pop(temp, &tempTop);
      if (bagWeight + y.weight <= 20)
        pushInBag(bag, &bagTop, &bagWeight, y);
    }

    if (bagWeight + x.weight <= 20)
      pushInBag(bag, &bagTop, &bagWeight, x);
  }

  float total = 0;
  cout.precision(1);
  cout << fixed;
  while (bagTop > -1)
  {
    x = pop(bag, &bagTop);
    total += x.value;
    cout << x.id << ' ' << x.value << ' ' << x.weight << endl;
  }
  cout << "weight:" << bagWeight << endl;
  cout << "value:" << total << endl;

  return 0;
}
