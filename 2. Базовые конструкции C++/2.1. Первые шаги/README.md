# 2.1. Первые шаги

### А. Печать текста

```cpp
#include <iostream>

int main() {
    std::cout << "C++ is a general-purpose programming language with a bias towards systems "
                 "programming that\n";
    std::cout << "  - is a better C\n";
    std::cout << "  - supports data abstraction\n";
    std::cout << "  - supports object-oriented programming\n";
    std::cout << "  - supports generic programming.\n";

    return 0;
}

```

### Б. Сумма чисел

```cpp
#include <iostream>


int main() {
    int a, b;

    std::cin >> a >> b;
    std::cout << a + b << std::endl;

    return 0;
}
```