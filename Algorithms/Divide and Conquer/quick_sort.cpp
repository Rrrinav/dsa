#include <algorithm>
#include <iostream>

int partition(int arr[], int low, int high)
{
  int pivot = arr[high];
  int i = low - 1;
  for (int j = low; j < high; j++)
  {
    if (arr[j] < pivot)
    {
      i++;
      std::swap(arr[i], arr[j]);
    }
  }
  std::swap(arr[i + 1], arr[high]);
  return i + 1;
}

void quick_sort(int arr[], int low, int high)
{
  if (low < high)
  {
    int pi = partition(arr, low, high);
    quick_sort(arr, low, pi - 1);
    quick_sort(arr, pi + 1, high);
  }
}

int main()
{
  int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
  quick_sort(arr, 0, 8);
  for (int i = 0; i < 9; i++) std::cout << arr[i] << ' ';
}
