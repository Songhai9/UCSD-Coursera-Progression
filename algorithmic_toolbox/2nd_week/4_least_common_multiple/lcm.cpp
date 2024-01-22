#include <iostream>

long long lcm_naive(int a, int b)
{
  for (long l = 1; l <= (long long)a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long)a * b;
}

long long euclid_gcd(int a, int b)
{
  if (b == 0)
    return a;
  else
    return euclid_gcd(b, a % b);
}

long long lcm_fast(long long a, long long b)
{
  if (a != 0 && b != 0)
    return (a * b) / euclid_gcd(a, b);
  return 0;
}

int main()
{
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
