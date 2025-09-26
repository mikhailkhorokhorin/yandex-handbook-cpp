#include <iostream>

int main() {
    int n;
    std::cin >> n;

    double result = 0.0;
    int sign = 1;

    for (int i = 1; i <= n; i++) {
        result += (sign * 1.0 / i);
        sign = -sign;
    }

    std::cout << result << std::endl;
    return 0;
}