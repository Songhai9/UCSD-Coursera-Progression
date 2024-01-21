def maxpairproduct(A):
    n = len(A)
    result = 0
    for f_index in range(n):
        for s_index in range(f_index + 1, n):
            if A[f_index] * A[s_index] > result:
                result = A[f_index] * A[s_index]
    return result


def maxpairproductfast(A):
    n = len(A)
    f_max = -1
    s_max = -1

    for index in range(n):
        if (f_max == -1) or (A[index] > A[f_max]):
            f_max = index

    for index in range(n):
        if (index != f_max) and ((s_max == -1) or (A[index] > A[s_max])):
            s_max = index

    return A[f_max] * A[s_max]


n = int(input())

A = [int(i) for i in input().split()]
print(maxpairproductfast(A))
