#include <iostream>

int main() {
    int number;
    std::cin >> number;

    int result = 0;

    while (number > 0) {
        result += number % 10;
        number /= 10;
    }

    std::cout << result << std::endl;

    return 0;
}