#include <iostream>

int binary_search(int x, int arr[], int n)
{
  int low = 0, high = n - 1;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (arr[mid] == x)
      return mid;
    else if (arr[mid] < x)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return -1;
}

int main()
{
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::cout << binary_search(5, arr, 9) << '\n';
}
