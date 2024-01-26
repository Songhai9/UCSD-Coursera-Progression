def list_last():
    arr = [0, 1]
    index = 2

    while True:
        arr.append((arr[index - 1] + arr[index - 2]) % 10)
        if arr[index] == 1 and arr[index - 1] == 0:
            index = index - 1
            break
        index += 1

    return arr


def fibonacci_sum(n):
    arr = list_last()
    number = (arr[(n + 2) % 60] - 1) % 10
    return number


if __name__ == '__main__':
    n = int(input())
    print(fibonacci_sum(n))
