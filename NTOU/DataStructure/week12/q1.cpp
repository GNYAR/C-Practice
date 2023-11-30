#include <iostream>
#include <vector>

using namespace std;

int main()
{
  vector<int> heap{NULL};
  int x;
  while (cin >> x)
  {
    heap.push_back(x);
    int i = heap.size() - 1;
    while (i > 1 && heap[i / 2] > x)
    {
      heap[i] = heap[i / 2];
      i /= 2;
    }
    heap[i] = x;

    for (int i = 1; i < heap.size(); i++)
      cout << '[' << i << ']' << heap[i] << ' ';
    cout << endl;
  }

  return 0;
}
