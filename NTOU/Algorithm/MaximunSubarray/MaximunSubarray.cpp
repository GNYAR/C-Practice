#include <iostream>
#include <vector>
#include <tuple>
#include <climits>

using namespace std;

// result(start, end, sum)
tuple<int, int, int> findMaxCrossingSubarray(vector<int> &arr, int start, int middle, int end);
tuple<int, int, int> findMaximumSubarray(vector<int> &arr, int start, int end);

tuple<int, int, int> findMaxCrossingSubarray(vector<int> &arr, int start, int middle, int end)
{
  int leftSum = INT_MIN, rightSum = INT_MIN;
  int leftIndex, rightIndex, sum, i;
  // left
  sum = 0;
  for (i = middle; i >= start; i--)
  {
    sum += arr[i];
    if (sum > leftSum)
    {
      leftSum = sum;
      leftIndex = i;
    }
  }
  // right
  sum = 0;
  for (i = middle + 1; i <= end; i++)
  {
    sum += arr[i];
    if (sum > rightSum)
    {
      rightSum = sum;
      rightIndex = i;
    }
  }
  return make_tuple(leftIndex, rightIndex, leftSum + rightSum);
}

tuple<int, int, int> findMaximumSubarray(vector<int> &arr, int start, int end)
{
  if (start == end)
    return make_tuple(start, end, arr[start]);
  int middle = (start + end) / 2;
  tuple<int, int, int> left = findMaximumSubarray(arr, start, middle);
  tuple<int, int, int> right = findMaximumSubarray(arr, middle + 1, end);
  tuple<int, int, int> cross = findMaxCrossingSubarray(arr, start, middle, end);
  int leftSum = get<2>(left);
  int rightSum = get<2>(right);
  int crossSum = get<2>(cross);
  if (leftSum > rightSum && leftSum > crossSum)
    return left;
  else if (rightSum > leftSum && rightSum > crossSum)
    return right;
  return cross;
}

int main()
{
  vector<int> arr;
  int input;
  while (cin >> input)
    arr.push_back(input);
  int sum = get<2>(findMaximumSubarray(arr, 0, arr.size() - 1));
  cout << sum << endl;
  return 0;
}
