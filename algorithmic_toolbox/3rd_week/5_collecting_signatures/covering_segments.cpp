#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment
{
    int start, end;
    bool has_signed = 0;
};

// Fonction de comparaison personnalisée
bool compareSegments(const Segment &a, const Segment &b)
{
    return a.end < b.end;
}

void sortSegments(vector<Segment> &segments)
{
    std::sort(segments.begin(), segments.end(), compareSegments);
}

vector<int> optimal_points(vector<Segment> &segments)
{
    vector<int> points;
    // write your code here
    sortSegments(segments);

    for (size_t i = 0; i < segments.size(); ++i)
    {
        if (!segments[i].has_signed)
        {
            points.push_back(segments[i].end);
            for (size_t j = 0; j < segments.size(); ++j)
            {
                if (segments[j].start <= segments[i].end && segments[j].end >= segments[i].end)
                    segments[j].has_signed = true;
            }
        }
    }
    return points;
}

int main()
{
    int n;
    std::cin >> n;
    vector<Segment> segments(n);
    for (size_t i = 0; i < segments.size(); ++i)
    {
        std::cin >> segments[i].start >> segments[i].end;
    }
    vector<int> points = optimal_points(segments);
    std::cout << points.size() << "\n";
    for (size_t i = 0; i < points.size(); ++i)
    {
        std::cout << points[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
