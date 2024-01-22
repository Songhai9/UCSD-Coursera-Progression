def find_cycle():
    previous = 0
    current = 1
    iterator = 0

    while True:
        previous, current = current, (previous + current) % 10
        iterator += 1
        if previous == 0 and current == 1:
            break

    return iterator


def formula(n):
    return (n * (n + 1)) / 2


def fibonacci_sum(n):
    if n <= 1:
        return n

    fibo_sum = formula(n)
    previous = 0
    current = 1

    last_digit = [0] * 60
    last_digit[1] = 1

    for index in range(2, len(last_digit)):
        (previous, current) = (current, (previous + current) % 10)
        last_digit[index] = current

    return last_digit[int(fibo_sum % 60)]


if __name__ == '__main__':
    n = int(input())
    print(fibonacci_sum(n))
