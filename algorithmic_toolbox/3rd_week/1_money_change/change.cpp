#include <iostream>

int get_change(int m)
{
  int n = 0;
  while (m >= 10)
  {
    m -= 10;
    n += 1;
  }

  while (m >= 5)
  {
    m -= 5;
    n += 1;
  }

  while (m > 0)
  {
    m -= 1;
    n += 1;
  }

  return n;
}

int main()
{
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
