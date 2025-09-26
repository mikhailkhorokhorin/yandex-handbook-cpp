# 2.1. Первые шаги

### A. Печать текста

```cpp
#include <iostream>

int main() {O
    std::cout << "C++ is a general-purpose programming language with a bias towards systems "
                 "programming that"
              << std::endl;
    std::cout << "  - is a better C" << std::endl;
    std::cout << "  - supports data abstraction" << std::endl;
    std::cout << "  - supports object-oriented programming" << std::endl;
    std::cout << "  - supports generic programming." << std::endl;

    return 0;
}
```

### B. Сумма чисел

```cpp
#include <iostream>

int main() {
    int a, b;

    std::cin >> a >> b;
    std::cout << a + b << std::endl;

    return 0;
}
```