def optimal_summands(n):
    summands = []
    last_summand = 0
    remaining = n

    while remaining > 0:
        next_summand = last_summand + 1
        # Ensure the next summand does not cause the remaining to be less than the subsequent summand
        if remaining - next_summand <= next_summand:
            summands.append(remaining)
            break
        else:
            summands.append(next_summand)
            last_summand = next_summand
            remaining -= next_summand

    return summands


if __name__ == '__main__':
    n = int(input())
    summands = optimal_summands(n)
    print(len(summands))
    print(*summands)
