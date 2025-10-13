# 4.3. Жизненный цикл объекта

### A. Жизнь объекта - 0

```cpp
#include "logger.h"

int main() {
    {
        Logger a;
    }
    {
        Logger b;
    }
    
    return 0;
}
```

### B. Жизнь объекта - 1

```cpp
#include "logger.h"

int main() {
    Logger a;
    Logger b = a;

    return 0;
}
```

### C. Жизнь объекта - 2

```cpp
#include <utility>

#include "logger.h"

int main() {
    Logger a;
    Logger b = std::move(a);

    return 0;
}
```

### D. Жизнь объекта - 3

```cpp
#include <utility>

#include "logger.h"

int main() {
    Logger a;
    Logger b;
    a = b;
    a = std::move(b);

    return 0;
}
```

### E. Жизнь объекта - 4

```cpp
#include "logger.h"

int main() {
    Logger a;
    Logger* b = new Logger;
    Logger* c = new Logger;
    delete b;
    delete c;
    
    return 0;
}
```

### F. Жизнь объекта - 5

```cpp
#include <vector>

#include "logger.h"

int main() {
    int n;
    std::cin >> n;

    std::vector<Logger> loggers(n);

    for (int i = 0; i != n; ++i)
        loggers.pop_back();

    return 0;
}
```

### G. Жизнь объекта - 6

```cpp
#include <vector>

#include "logger.h"

int main() {
    int n;
    std::cin >> n;

    std::vector<Logger*> loggers(n);

    for (int i = 0; i != n; ++i)
        loggers[i] = new Logger;

    for (int i = 0; i != n; ++i)
        delete loggers[i];

    return 0;
}
```

### H. TimeGuard

```cpp
#include <chrono>
#include <iostream>
#include <string>

class TimerGuard {
   private:
    std::string message_;
    std::ostream& out_;
    std::chrono::high_resolution_clock::time_point start_;

   public:
    TimerGuard(std::string message = "", std::ostream& out = std::cout)
        : message_(std::move(message)),
          out_(out),
          start_(std::chrono::high_resolution_clock::now()) {
    }

    ~TimerGuard() {
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start_;
        out_ << message_ << diff.count() << std::endl;
    }
};
```

