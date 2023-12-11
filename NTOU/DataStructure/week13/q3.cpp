#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Plates
{
private:
  int cap;
  vector<vector<int>> stacks;
  set<int> s;

public:
  Plates(int capacity) : cap(capacity) {}

  void push(int val)
  {
    if (s.empty())
    {
      s.insert(stacks.size());
      stacks.push_back({});
    }
    int top = *s.begin();
    stacks[top].push_back(val);
    if (stacks[top].size() == cap)
      s.erase(top);
  }

  int pop()
  {
    return popAtStack(stacks.size() - 1);
  }

  int popAtStack(int index)
  {
    if (index < 0 || index >= stacks.size() || stacks[index].empty())
      return -1;

    int x = stacks[index].back();
    stacks[index].pop_back();
    s.insert(index);

    while (stacks.size() && stacks.back().empty())
    {
      stacks.pop_back();
      s.erase(stacks.size());
    }
    return x;
  }
};

int main()
{
  string s;
  int n;
  cin >> n;
  Plates plate(n);
  while (cin >> s)
  {
    Plates D = Plates(2); // Initialize with capacity = 2
    D.push(1);
    D.push(2);
    D.push(3);
    D.push(4);
    D.push(5);
    /* The stacks are now:
       2  4
       1  3  5
      ﹈ ﹈ ﹈
    */
    D.popAtStack(0); // Returns 2.

    /* The stacks are now:
          4
       1  3  5
      ﹈ ﹈ ﹈
    */
    D.push(20);
    /* The stacks are now:
      20  4
       1  3  5
      ﹈ ﹈ ﹈
    */
    D.push(21);
    /* The stacks are now:
      20  4 21
       1  3  5
      ﹈ ﹈ ﹈
    */
    D.popAtStack(0); // Returns 20.
    /* The stacks are now:
          4 21
       1  3  5
      ﹈ ﹈ ﹈
    */
    D.popAtStack(2); // Returns 21.
    /* The stacks are now:
          4
       1  3  5
      ﹈ ﹈ ﹈
    */
    D.pop(); // Returns 5.
    /* The stacks are now:
          4
       1  3
      ﹈ ﹈
    */
    D.pop(); // Returns 5.
    /* The stacks are now:
          4
       1  3
      ﹈ ﹈
    */
    D.pop(); // Returns 5.
    /* The stacks are now:
          4
       1  3
      ﹈ ﹈
    */
    D.pop(); // Returns 4.
    /* The stacks are now:
       1  3
      ﹈ ﹈
    */
    D.pop(); // Returns 3.
    /* The stacks are now:
       1
      ﹈
    */
    D.pop(); // Returns 1.
    // There is no stack.
    D.pop(); // Returns -1.

    if (s == "pop")
      cout
          << plate.pop() << '\n';
    else if (s == "push")
    {
      cin >> n;
      plate.push(n);
    }
    else if (s == "popAtStack")
    {
      cin >> n;
      cout << plate.popAtStack(n) << '\n';
    }
  }
  return 0;
}
