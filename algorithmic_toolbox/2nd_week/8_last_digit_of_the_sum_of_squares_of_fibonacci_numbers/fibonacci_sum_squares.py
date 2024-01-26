def make_last_digit_list():
    last_list = [0, 1]
    index_previous = 0
    index_current = 1
    while True:
        last_list.append((last_list[index_current] + last_list[index_previous]) % 10)
        index_current += 1
        index_previous += 1
        if last_list[index_current] == 1 and last_list[index_previous] == 0:
            last_list.pop()
            last_list.pop()
            break
    return last_list


def fibo_sum_square(n):
    last_digit_list = make_last_digit_list()
    return last_digit_list[n % 60] * last_digit_list[(n + 1) % 60] % 10


if __name__ == '__main__':
    n = int(input())
    print(fibo_sum_square(n))
