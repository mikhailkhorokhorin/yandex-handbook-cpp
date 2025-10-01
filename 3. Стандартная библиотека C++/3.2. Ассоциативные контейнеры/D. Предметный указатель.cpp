#include <iostream>
#include <map>
#include <set>
#include <string>

int main() {
    int n;
    std::cin >> n;

    std::map<int, std::set<std::string>> index;
    std::string word;
    int page;

    for (int i = 0; i < n; i++) {
        std::cin >> word >> page;
        index[page].insert(word);
    }

    for (auto& elem : index) {
        std::cout << elem.first;
        for (auto& w : elem.second)
            std::cout << " " << w;

        std::cout << std::endl;
    }

    return 0;
}