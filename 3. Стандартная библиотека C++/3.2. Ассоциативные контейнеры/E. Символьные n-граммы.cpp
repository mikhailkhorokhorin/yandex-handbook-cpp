#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

int main() {
    int m, n;
    std::cin >> m >> n;

    std::unordered_map<std::string, int> freq;
    std::string word;

    for (int i = 0; i < m; i++) {
        std::cin >> word;

        for (size_t j = 0; j + n <= word.size(); j++) {
            std::string gram = word.substr(j, n);
            freq[gram]++;
        }
    }

    std::vector<std::pair<std::string, int>> grams(freq.begin(), freq.end());

    std::sort(grams.begin(), grams.end(), [](const auto& a, const auto& b) {
        if (a.second != b.second)
            return a.second > b.second;
        return a.first < b.first;
    });

    for (auto& p : grams)
        std::cout << p.first << " - " << p.second << std::endl;

    return 0;
}