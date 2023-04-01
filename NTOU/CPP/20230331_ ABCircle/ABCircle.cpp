#include <iostream>

using namespace std;

class Parking
{
private:
  int hr, min;

public:
  void arrive(int, int);
  void leave(int, int);
};

void Parking::arrive(int hr, int min)
{
  this->hr = hr;
  this->min = min;
}

void Parking::leave(int hr, int min)
{
  int tempHr = this->hr;
  int cnt = 0, a = 50, fee = 0;
  while (tempHr < hr)
  {
    fee += a;

    if (++cnt == 2)
      a = 40;
    else if (cnt == 10)
      a = 30;

    tempHr++;
  }
  if (min > this->min)
    fee += a;

  cout << fee << endl;
}

int main()
{
  int hr, min;
  while (cin >> hr >> min)
  {
    Parking car;
    car.arrive(hr, min);
    cin >> hr >> min;
    car.leave(hr, min);
  }

  return 0;
}
