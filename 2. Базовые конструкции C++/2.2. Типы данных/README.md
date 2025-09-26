# 2.1. Типы данных

### A. Дюймы

```cpp
#include <iostream>

int main() {
    double centimeters;

    std::cin >> centimeters;
    std::cout << centimeters / 2.54 << std::endl;

    return 0;
}
```

### B. Арифметическая прогрессия

```cpp
#include <iostream>

int main() {
    unsigned long long n;

    std::cin >> n;
    std::cout << n * (n + 1) / 2 << std::endl;

    return 0;
}
```