#include <iostream>
#include <climits>
#define INPUT_MAX 50000

using namespace std;

void loadArray(int dest[], int arr[], int start, int end);
void merge(int arr[], int start, int middle, int end);
void mergeSort(int arr[], int start, int end);
void printArray(int arr[], int cnt);

void loadArray(int dest[], int arr[], int start, int end)
{
  int i = 0;
  for (; start <= end; start++)
    dest[i++] = arr[start];
}

void merge(int arr[], int start, int middle, int end)
{
  int left[INPUT_MAX], right[INPUT_MAX];
  loadArray(left, arr, start, middle);
  loadArray(right, arr, middle + 1, end);
  left[middle - start + 1] = INT_MAX;
  right[end - middle] = INT_MAX;

  int i = 0, j = 0;
  for (; start <= end; start++)
    arr[start] = (left[i] > right[j]) ? right[j++] : left[i++];
}

void mergeSort(int arr[], int start, int end)
{
  if (start >= end)
    return;
  int middle = (end + start) / 2;
  mergeSort(arr, start, middle);
  mergeSort(arr, middle + 1, end);
  merge(arr, start, middle, end);
}

void printArray(int arr[], int cnt)
{
  for (int i = 0; i < cnt; i++)
    cout << arr[i] << " ";
  cout << endl;
}

int main()
{
  int arr[INPUT_MAX];
  int cnt = 0;
  int i = 0;
  while (cin >> i)
    arr[cnt++] = i;
  mergeSort(arr, 0, cnt - 1);
  printArray(arr, cnt);
  return 0;
}
