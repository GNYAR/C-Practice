#include <iostream>
#include <iomanip>

using namespace std;

const int MAX_MINUTE = 10;

class Timer
{
private:
  int min, sec;

public:
  Timer() : min(0), sec(0) {}

  Timer(int s) : min(s / 60), sec(s % 60)
  {
    while (min >= MAX_MINUTE)
      min -= MAX_MINUTE;
  }

  Timer(int m, int s) : min(m), sec(s)
  {
    while (min >= MAX_MINUTE)
      min -= MAX_MINUTE;
  }

  Timer operator++();
  Timer operator--(int);
  friend Timer operator+(const Timer &a, const Timer &b);
  friend ostream &operator<<(ostream &out, const Timer &foo);
};

int main()
{

  int input_1, input_2;
  Timer foo;
  while (cin >> input_1 >> input_2)
  {
    foo = foo + input_1;
    cout << foo << endl;
    foo = input_2 + foo;
    cout << foo << endl;
    cout << ++foo << endl;
    foo = input_2;
    for (int i = input_2; i >= 0; --i)
      cout << foo-- << endl;
  }

  return 0;
}

Timer Timer::operator++()
{
  int s = sec + 1;
  min = min + (s / 60);
  sec = s % 60;
  return Timer(min, sec);
}

Timer Timer::operator--(int)
{
  Timer t = Timer(min, sec);
  int s = sec - 1;
  if (s < 0)
    min--;
  sec = s < 0 ? 59 : s;
  return t;
}

Timer operator+(const Timer &a, const Timer &b)
{
  return Timer((a.min + b.min) * 60 + a.sec + b.sec);
}

ostream &operator<<(ostream &out, const Timer &foo)
{
  out << setw(2) << setfill('0') << foo.min << " : "
      << setw(2) << setfill('0') << foo.sec;
  return out;
}
