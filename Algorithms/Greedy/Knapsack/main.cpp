#include <algorithm>
#include <iostream>
#include <vector>

struct Item
{
  int weight;
  int value;

  double valuePerWeight() const { return static_cast<double>(value) / weight; }
};

bool compare(const Item &a, const Item &b) { return a.valuePerWeight() > b.valuePerWeight(); }

double fractionalKnapsack(int capacity, const std::vector<Item> &items)
{
  std::vector<Item> sortedItems = items;
  std::sort(sortedItems.begin(), sortedItems.end(), compare);

  double totalValue = 0.0;
  int remainingCapacity = capacity;

  for (const auto &item : sortedItems)
  {
    if (item.weight <= remainingCapacity)
    {
      totalValue += item.value;
      remainingCapacity -= item.weight;
    }
    else
    {
      totalValue += item.valuePerWeight() * remainingCapacity;
      break;
    }
  }

  return totalValue;
}

int main()
{
  int capacity = 50;
  std::vector<Item> items = {{10, 60}, {20, 100}, {30, 120}};

  double maxValue = fractionalKnapsack(capacity, items);
  std::cout << "Maximum value in knapsack = " << maxValue << std::endl;

  return 0;
}
