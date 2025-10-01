#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_set<int> seen;
    int x;

    while (std::cin >> x) {
        if (seen.count(x)) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
            seen.insert(x);
        }
    }

    return 0;
}