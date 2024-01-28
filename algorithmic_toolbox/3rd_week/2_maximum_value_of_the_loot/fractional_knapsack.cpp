#include <iostream>
#include <vector>

using std::vector;

int get_max(vector<float> array)
{
  int max_index = 0;
  int size = array.size();
  for (int index = 0; index < size; index++)
  {
    if (array[index] > array[max_index])
      max_index = index;
  }

  return max_index;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values)
{
  double value = 0.0;
  int n = weights.size();
  vector<float> unit_price(n);
  vector<bool> used(n, false);

  for (int i = 0; i < n; i++)
  {
    unit_price[i] = static_cast<float>(values[i]) / weights[i];
  }

  while (capacity > 0)
  {
    int max_index = -1;
    for (int i = 0; i < n; i++)
    {
      if (!used[i] && (max_index == -1 || unit_price[i] > unit_price[max_index]))
      {
        max_index = i;
      }
    }

    if (max_index == -1)
      break;

    int weight_to_take = std::min(weights[max_index], capacity);
    value += weight_to_take * unit_price[max_index];
    capacity -= weight_to_take;
    used[max_index] = true;
  }

  return value;
}

int main()
{
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++)
  {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
