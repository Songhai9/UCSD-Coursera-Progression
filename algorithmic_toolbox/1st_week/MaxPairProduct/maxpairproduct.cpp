#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

long long maxpairproduct(const vector<long long> &A)
{
    long long result = 0;
    int n = A.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (A[i] * A[j] > result)
                result = A[i] * A[j];
        }
    }

    return result;
}

long long maxpairproductfast(const vector<long long> &A)
{
    int n = A.size();

    int index_max1 = -1;
    int index_max2 = -1;

    for (int i = 0; i < n; i++)
    {
        if (index_max1 == -1 || A[i] > A[index_max1])
            index_max1 = i;
    }

    for (int i = 0; i < n; i++)
    {
        if (i != index_max1 && (index_max2 == -1 || A[i] > A[index_max2]))
            index_max2 = i;
    }

    return A[index_max1] * A[index_max2];
}

int main()
{
    int n;
    cin >> n;

    vector<long long> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    long long result = maxpairproductfast(A);

    cout << result << endl;

    return 0;
}