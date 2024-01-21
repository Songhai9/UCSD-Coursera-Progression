def EuclidGCD(a, b):
    if b == 0:
        return a
    r = a % b
    return EuclidGCD(b, r)


print(EuclidGCD(357, 234))
