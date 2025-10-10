#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
    int k;
    std::cin >> k;

    std::map<std::string, int> freq;
    std::string word;

    while (std::cin >> word) {
        for (char &c : word)
            c = tolower(c);
        ++freq[word];
    }

    std::vector<std::pair<std::string, int>> v(freq.begin(), freq.end());

    sort(v.begin(), v.end(), [](const auto &a, const auto &b) {
        if (a.second != b.second)
            return a.second > b.second;
        return a.first < b.first;
    });

    for (int i = 0; i < k && i < (int)v.size(); ++i)
        std::cout << v[i].first << '\t' << v[i].second << std::endl;
}
