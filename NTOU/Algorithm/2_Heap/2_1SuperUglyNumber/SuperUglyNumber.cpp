#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
  int n, k;
  cin >> n >> k;
  long nums[n + 1];
  nums[0] = 0;
  nums[1] = 1;
  vector<pair<int, int>> primeIndicex; // (prime, index of multiplicand)
  int p;
  for (int i = 0; i < k; i++)
  {
    cin >> p;
    primeIndicex.push_back(make_pair(p, 1));
  }

  for (int i = 2; i <= n; i++)
  {
    // Find the minimum value among the prime number multiples.
    long next = LONG_MAX;
    for (int j = 0; j < k; j++)
      next = min(next, nums[primeIndicex[j].second] * primeIndicex[j].first);
    nums[i] = next;
    // Increment the indices of the prime number multiples that contribute to the minimum value.
    for (int j = 0; j < k; j++)
      if (next == nums[primeIndicex[j].second] * primeIndicex[j].first)
        primeIndicex[j].second++;
  }

  cout << nums[n] << endl;
  return 0;
}

/* Heap (TLE)

int main()
{
  int n, k;
  cin >> n >> k;
  int *primes = new int[k];
  priority_queue<long, vector<long>, greater<long>> pq;
  pq.push(1);
  for (int i = 0; i < k; i++)
    cin >> primes[i];
  long x;
  while (n--)
  {
    x = pq.top();
    while (pq.size() && x == pq.top())
      pq.pop();
    for (int i = 0; i < k; i++)
      pq.push(x * primes[i]);
  }
  cout << x << endl;
  return 0;
}

*/
