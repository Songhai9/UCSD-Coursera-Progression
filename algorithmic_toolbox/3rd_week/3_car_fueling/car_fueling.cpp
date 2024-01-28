#include <iostream>
#include <vector>
#include <cmath>

using std::cin;
using std::cout;
using std::max;
using std::vector;

int compute_min_refills(int dist, int tank, vector<int> &stops)
{
    int refills = 0;
    int current_pos = 0;
    int remaining = tank;

    // Insert a 'stop' at the starting point (0)
    stops.insert(stops.begin(), 0);

    // Insert a 'stop' at the destination (dist)
    stops.push_back(dist);

    for (int i = 0; i < stops.size() - 1; ++i)
    {
        int distance_to_next = stops[i + 1] - stops[i];

        // Check if the distance to the next stop is greater than the tank's capacity
        if (distance_to_next > tank)
        {
            return -1;
        }

        // Check if remaining fuel is sufficient to reach the next stop
        if (remaining >= distance_to_next)
        {
            remaining -= distance_to_next;
        }
        else
        {
            // Refill and reset remaining fuel
            refills++;
            remaining = tank - distance_to_next;
        }
    }

    return refills;
}

int main()
{
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
