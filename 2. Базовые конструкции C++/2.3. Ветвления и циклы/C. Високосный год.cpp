#include <iostream>

int main() {
    int year;
    std::cin >> year;

    bool leap = (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);

    std::cout << (leap ? "YES" : "NO") << std::endl;

    return 0;
}