#include <iostream>
#include <vector>

int main() {
    int length = 0;
    std::cin >> length;

    std::vector<int> guests(length);

    for (int i = 0; i < length; ++i) {
        std::cin >> guests[i];
    }

    std::vector<int> places(length);

    for (int i = 0; i < length; ++i) {
        places[guests[i] - 1] = i + 1;
    }

    for (int i = 0; i < length; ++i) {
        std::cout << places[i] << ' ';
    }

    std::cout << std::endl;
    return 0;
}