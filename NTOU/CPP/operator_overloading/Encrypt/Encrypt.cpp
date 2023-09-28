#include <iostream>
#include <iomanip>
#include <bitset>

using namespace std;

int main()
{
  int k;
  string msg;
  cin >> k >> msg;

  int r = (msg.size() * 5) % 4;
  string binary(4 - r, '0');
  for (int i = 0; msg[i]; i++)
  {
    int n = ((msg[i] - 65 + k) % 26) + 1;
    bitset<5> bits(n);
    binary += bits.to_string();
  }

  int cnt = 0;
  for (int i = 0; binary[i]; i += 4)
  {
    int n = stoi(binary.substr(i, 4), 0, 2);

    if (i == 0 && n == 0)
      continue;

    cout << hex << n;
    cnt++;
  }
  cout << string(4 - (cnt % 4), '0') << endl;
}
