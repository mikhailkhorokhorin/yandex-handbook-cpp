# 2.1. Первые шаги

### A. Ход ферзя

```cpp
#include <iostream>

int main() {
    int startx, startY, endX, endY;
    std::cin >> startx >> startY >> endX >> endY;

    bool condition = startx == endX || startY == endY || abs(startx - endX) == abs(startY - endY);

    std::cout << (condition ? "YES" : "NO") << std::endl;

    return 0;
}
```

### B. Прямоугольный треугольник

```cpp
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
```

### C. Високосный год

```cpp
#include <iostream>

int main() {
    int year;
    std::cin >> year;

    bool leap = (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);

    std::cout << (leap ? "YES" : "NO") << std::endl;

    return 0;
}
```

### D. Количество дней в месяце

```cpp
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
```

### E. Печать календаря

```cpp
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
```

### F. Сумма цифр

```cpp
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
```

### G. ln 2

```cpp
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
```