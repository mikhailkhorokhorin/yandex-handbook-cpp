#include <iostream>
#include <set>
#include <string>

int main() {
    std::set<char> chars;

    std::string word;
    std::cin >> word;

    chars = std::set<char>(word.begin(), word.end());

    while (std::cin >> word) {
        std::set<char> current(word.begin(), word.end());
        std::set<char> intersection;

        for (char c : chars) {
            if (current.count(c))
                intersection.insert(c);
        }

        chars = std::move(intersection);
    }

    for (char c : chars)
        std::cout << c;

    std::cout << std::endl;

    return 0;
}