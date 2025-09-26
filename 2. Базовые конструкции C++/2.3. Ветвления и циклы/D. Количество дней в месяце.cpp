#include <iostream>

int main() {
    int month, year;

    std::cin >> month >> year;
    int days;

    if (month == 2) {
        bool leap = (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
        days = leap ? 29 : 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        days = 30;
    } else {
        days = 31;
    }

    std::cout << days << std::endl;

    return 0;
}