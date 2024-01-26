#include <iostream>
#include <vector>
using std::vector;

std::vector<int> get_cycle_list()
{
    std::vector<int> last_list{0, 1};

    do
    {
        int next = (last_list[last_list.size() - 2] + last_list.back()) % 10;
        last_list.push_back(next);
    } while (!(last_list[last_list.size() - 2] == 0 && last_list.back() == 1));

    // Removing the last two elements (0 and 1) as they are part of the next cycle
    last_list.pop_back();
    last_list.pop_back();

    return last_list;
}

int get_fibonacci_partial_sum_fast(long long from, long long to)
{
    vector<int> last_list = get_cycle_list();
    int end_index = (to + 2) % last_list.size();
    int debut_index = (from + 1) % last_list.size();

    return (last_list[end_index] - last_list[debut_index] + 10) % 10;
}

int main()
{
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';

    return 0;
}
