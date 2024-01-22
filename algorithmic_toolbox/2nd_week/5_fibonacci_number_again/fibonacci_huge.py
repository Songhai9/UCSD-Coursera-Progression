def find_cycle(m):
    previous, current = 0, 1
    for i in range(0, m * m):
        previous, current = current, (previous + current) % m
        if previous == 0 and current == 1:
            return i + 1


def fibonacci_huge_fast(n, m):
    pisano_period = find_cycle(m)
    n = n % pisano_period

    previous, current = 0, 1
    if n == 0:
        return 0
    elif n == 1:
        return 1

    for _ in range(n - 1):
        previous, current = current, (previous + current) % m

    return current


if __name__ == '__main__':
    n, m = map(int, input().split())
    print(fibonacci_huge_fast(n, m))
