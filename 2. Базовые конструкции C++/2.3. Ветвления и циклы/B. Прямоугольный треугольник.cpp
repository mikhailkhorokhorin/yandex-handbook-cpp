#include <iostream>

int main() {
    int side1, side2, side3;

    std::cin >> side1 >> side2 >> side3;

    if (side1 + side2 <= side3 || side1 + side3 <= side2 || side2 + side3 <= side1) {
        std::cout << "UNDEFINED" << std::endl;
        return 0;
    }

    bool condition1 = side1 * side1 == side2 * side2 + side3 * side3;
    bool condition2 = side2 * side2 == side1 * side1 + side3 * side3;
    bool condition3 = side3 * side3 == side1 * side1 + side2 * side2;

    std::cout << (condition1 || condition2 || condition3 ? "YES" : "NO") << std::endl;

    return 0;
}