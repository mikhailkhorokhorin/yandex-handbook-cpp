# 3.1. Последовательные контейнеры

### A. Шаблонный Print

```cpp
#include <iostream>
#include <string>

template <typename T>
void Print(const T& vect, const std::string& sep) {
    bool first = true;

    for (const auto& el : vect) {
        if (!first)
            std::cout << sep;
        else
            first = false;

        std::cout << el;
    }

    std::cout << std::endl;
}
```

### B. Проверка работ

```cpp
#include <deque>
#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;

    std::deque<std::string> works;

    for (int i = 0; i < n; ++i) {
        std::string Surname, position;
        std::cin >> Surname >> position;

        if (position == "top")
            works.push_front(Surname);
        else
            works.push_back(Surname);
    }

    int m;
    std::cin >> m;

    for (int i = 0; i < m; ++i) {
        int x;
        std::cin >> x;

        std::cout << works[x - 1] << std::endl;
    }
    return 0;
}
```

### C. Вагоны

```cpp
#include <deque>
#include <iostream>
#include <string>

void MakeTrain() {
    std::deque<int> train;
    std::string command;

    while (std::cin >> command) {
        int m;
        std::cin >> m;

        if (command == "+left") {
            train.push_front(m);
        } else if (command == "+right") {
            train.push_back(m);
        } else if (command == "-left") {
            if (m >= (int)train.size())
                train.clear();
            else
                train.erase(train.begin(), train.begin() + m);

        } else if (command == "-right") {
            if (m >= (int)train.size())
                train.clear();
            else
                train.erase(train.end() - m, train.end());
        }
    }

    for (size_t i = 0; i < train.size(); ++i) {
        if (i > 0)
            std::cout << ' ';
        std::cout << train[i];
    }
    
    std::cout << std::endl;
}
```

### D. Ctrl+X, Ctrl+V

```cpp
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> file;
    std::string line;

    while (std::getline(std::cin, line)) {
        file.push_back(line);
        if (line.empty())
            break;
    }

    int cursor = 0;
    std::string buffer = "";

    while (std::getline(std::cin, line)) {
        if (line == "Down") {
            if (cursor + 1 < (int)file.size())
                cursor++;
        } else if (line == "Up") {
            if (cursor > 0)
                cursor--;
        } else if (line == "Ctrl+X") {
            if (!file[cursor].empty()) {
                buffer = file[cursor];
                file.erase(file.begin() + cursor);
                if (cursor >= (int)file.size() && !file.empty())
                    cursor = (int)file.size() - 1;
            }
        } else if (line == "Ctrl+V") {
            if (!buffer.empty()) {
                file.insert(file.begin() + cursor, buffer);
                cursor++;
            }
        }
    }

    for (size_t i = 0; i < file.size(); i++) {
        std::cout << file[i] << std::endl;
    }

    return 0;
}

```

### E. Ctrl+X, Ctrl+V - 2

```cpp
#include <iostream>
#include <list>
#include <string>

int main() {
    std::list<std::string> file;
    std::string line;

    while (std::getline(std::cin, line)) {
        if (line.empty())
            break;
        file.push_back(line);
    }

    auto cursor = file.begin();
    std::list<std::string> buffer;

    bool shiftPressed = false;
    int shiftOffset = 0;
    auto shift = file.begin();

    std::string command;
    while (std::cin >> command) {
        if (command == "Up") {
            if (cursor == file.begin())
                continue;

            --cursor;
            if (!shiftPressed)
                shift = cursor;
            else
                --shiftOffset;

        } else if (command == "Down") {
            if (cursor == file.end())
                continue;

            ++cursor;
            if (!shiftPressed)
                shift = cursor;
            else
                ++shiftOffset;

        } else if (command == "Ctrl+X") {
            if (shift == cursor && cursor == file.end())
                continue;

            buffer.clear();

            if (shift == cursor) {
                auto toSplice = cursor;
                cursor = std::next(cursor);
                buffer.splice(buffer.begin(), file, toSplice);
            } else if (shiftOffset < 0) {
                buffer.splice(buffer.begin(), file, cursor, shift);
                cursor = shift;
            } else {
                buffer.splice(buffer.begin(), file, shift, cursor);
            }

            shiftPressed = false;
            shift = cursor;
            shiftOffset = 0;
        } else if (command == "Ctrl+V") {
            if (buffer.empty())
                continue;

            if (shiftOffset < 0)
                cursor = file.erase(cursor, shift);
            else if (shiftOffset > 0)
                cursor = file.erase(shift, cursor);

            file.insert(cursor, buffer.begin(), buffer.end());

            shiftPressed = false;
            shift = cursor;
            shiftOffset = 0;
        } else if (command == "Shift") {
            shiftPressed = true;
        }
    }

    for (const auto &x : file) 
        std::cout << x << std::endl;
}
```
