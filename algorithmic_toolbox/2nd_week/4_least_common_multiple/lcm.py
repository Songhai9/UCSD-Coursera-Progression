def lcm(a, b):
    for l in range(1, a * b + 1):
        if l % a == 0 and l % b == 0:
            return l

    assert False


def euclid_gcd(a, b):
    if b == 0:
        return a
    else:
        return euclid_gcd(b, a % b)


def lcm_fast(a, b):
    if a != 0 and b != 0:
        return int((a * b) / euclid_gcd(a, b))


if __name__ == '__main__':
    a, b = map(int, input().split())
    print(lcm_fast(a, b))
