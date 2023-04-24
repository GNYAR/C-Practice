#include <iostream>
#include <vector>

using namespace std;

class RQueue
{
private:
  vector<int> queue;

public:
  RQueue(int);
  int shift();
  void moveToHead(int);
};

RQueue::RQueue(int n)
{
  for (int i = 1; i <= n; i++)
    queue.push_back(i);
}

int RQueue::shift()
{
  int n = queue.front();
  queue.erase(queue.begin());
  queue.push_back(n);
  return n;
}

void RQueue::moveToHead(int id)
{
  for (int i = 0; i < queue.size(); i++)
  {
    if (queue[i] == id)
      queue.erase(queue.begin() + i);
  }

  queue.insert(queue.begin(), id);
}

int main()
{
  int p, c, cnt = 0;
  cin >> p >> c;
  while (p || c)
  {
    RQueue q = RQueue(p);
    cout << "Case " << ++cnt << ":" << endl;
    while (c--)
    {
      char cmd;
      cin >> cmd;
      if (cmd == 'N')
      {
        cout << q.shift() << endl;
        continue;
      }
      int id;
      cin >> id;
      q.moveToHead(id);
    }
    cin >> p >> c;
  }

  return 0;
}
