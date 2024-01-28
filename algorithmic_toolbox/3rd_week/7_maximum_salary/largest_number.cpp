#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;

bool is_max(const string &a, const string &b)
{
    return a + b > b + a;
}

void SortArray(vector<string> &a)
{
    std::sort(a.begin(), a.end(), is_max);
}

string largest_number(vector<string> a)
{
    SortArray(a);

    std::stringstream ret;
    for (size_t i = 0; i < a.size(); i++)
    {
        ret << a[i];
    }
    string result;
    ret >> result;
    return result;
}

int main()
{
    int n;
    std::cin >> n;
    vector<string> a(n);
    for (size_t i = 0; i < a.size(); i++)
    {
        std::cin >> a[i];
    }
    std::cout << largest_number(a);
    std::cout << std::endl;
    return 0;
}
