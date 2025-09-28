#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int len;
    std::cin >> len;

    std::vector<std::pair<int, int>> points(len, {0, 0});
    for (int i = 0; i < len; ++i)
        std::cin >> points[i].first >> points[i].second;

    std::sort(points.begin(), points.end(), [](const auto& a, const auto& b) {
        long long da = 1LL * a.first * a.first + 1LL * a.second * a.second;
        long long db = 1LL * b.first * b.first + 1LL * b.second * b.second;
        if (da == db) {
            if (a.first == b.first)
                return a.second < b.second;
            return a.first < b.first;
        }
        return da < db;
    });

    for (const std::pair<int, int>& p : points)
        std::cout << p.first << " " << p.second << std::endl;

    return 0;
}