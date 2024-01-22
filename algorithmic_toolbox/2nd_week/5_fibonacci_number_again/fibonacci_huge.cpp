#include <iostream>

long long find_cycle(long long m)
{
    long long previous = 0;
    long long current = 1;
    long long temp;

    for (long long i = 0; i < m * m; i++)
    {
        temp = current;
        current = (current + previous) % m;
        previous = temp;

        // Check for the start of a new cycle
        if (previous == 0 && current == 1)
            return i + 1;
    }

    return 0;
}

long long fibonacci_huge_fast(long long n, long long m)
{
    if (m == 0)
        return 0;

    long long cycle = find_cycle(m);
    n = n % cycle;

    long long previous = 0;
    long long current = 1;

    for (long long i = 0; i < n - 1; i++)
    {
        long long temp = current;
        current = (current + previous) % m;
        previous = temp;
    }

    return current;
}

int main()
{
    long long n, m;
    std::cin >> n >> m;
    std::cout << fibonacci_huge_fast(n, m) << '\n';
}
