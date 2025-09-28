#include <iostream>

int main() {
    int n, k;
    std::cin >> n >> k;

    for (int i = 1; i < n; ++i)
        std::cout << "   ";

    int currentDay = n;

    for (int day = 1; day <= k; ++day) {
        if (day < 10)
            std::cout << " ";

        std::cout << day;

        if (currentDay == 7) {
            std::cout << std::endl;
            currentDay = 1;
        } else {
            std::cout << " ";
            currentDay += 1;
        }
    }

    if (currentDay != 1)
        std::cout << std::endl;
}