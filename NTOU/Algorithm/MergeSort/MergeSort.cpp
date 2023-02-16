#include <iostream>
#include <vector>
#include <climits>
#define INPUT_MAX 50000

using namespace std;

void loadArray(vector<int> &dest, int arr[], int start, int end);
void merge(int arr[], int start, int middle, int end);
void mergeSort(int arr[], int start, int end);
void printArray(int arr[], int cnt);

void loadArray(vector<int> &dest, int arr[], int start, int end)
{
  int i = 0;
  for (; start <= end; start++)
    dest[i++] = arr[start];
}

void merge(int arr[], int start, int middle, int end)
{
  vector<int> temp(end - start + 1);
  loadArray(temp, arr, start, end);

  int rightEnd = temp.size() - 1;
  int leftEnd = rightEnd / 2;
  int i = 0, j = leftEnd + 1;
  for (; start <= end; start++)
  {
    int left = (i > leftEnd) ? INT_MAX : temp[i];
    int right = (j > rightEnd) ? INT_MAX : temp[j];
    if (left > right)
    {
      arr[start] = right;
      j++;
    }
    else
    {
      arr[start] = left;
      i++;
    }
  }
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
