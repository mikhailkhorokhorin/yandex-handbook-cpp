# 3.2. Ассоциативные контейнеры

### A. Встречалось ли число раньше?

```cpp
#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_set<int> seen;
    int x;

    while (std::cin >> x) {
        if (seen.count(x)) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
            seen.insert(x);
        }
    }

    return 0;
}
```

### B. Общие буквы

```cpp
#include <iostream>
#include <set>
#include <string>

int main() {
    std::set<char> chars;

    std::string word;
    std::cin >> word;

    chars = std::set<char>(word.begin(), word.end());

    while (std::cin >> word) {
        std::set<char> current(word.begin(), word.end());
        std::set<char> intersection;

        for (char c : chars) {
            if (current.count(c))
                intersection.insert(c);
        }

        chars = std::move(intersection);
    }

    for (char c : chars)
        std::cout << c;

    std::cout << std::endl;

    return 0;
}
```


### C. Файловая система

```cpp
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

int main() {
    std::set<std::string> dirs;
    std::string path;

    while (std::getline(std::cin, path)) {
        std::vector<std::string> parts;
        std::string item;

        std::stringstream ss(path);

        while (std::getline(ss, item, '/'))
            parts.push_back(item);

        std::string cur = "/";
        dirs.insert(cur);

        for (size_t i = 1; i + 1 < parts.size(); i++) {
            cur += parts[i] + "/";
            dirs.insert(cur);
        }
    }

    for (auto& dir : dirs) {
        std::cout << dir << std::endl;
    }

    return 0;
}
```


### D. Предментный указатель

```cpp
#include <iostream>
#include <map>
#include <set>
#include <string>

int main() {
    int n;
    std::cin >> n;

    std::map<int, std::set<std::string>> index;
    std::string word;
    int page;

    for (int i = 0; i < n; i++) {
        std::cin >> word >> page;
        index[page].insert(word);
    }

    for (auto& elem : index) {
        std::cout << elem.first;
        for (auto& w : elem.second)
            std::cout << " " << w;

        std::cout << std::endl;
    }

    return 0;
}
```


### E. Символьные n-граммы

```cpp
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

int main() {
    int m, n;
    std::cin >> m >> n;

    std::unordered_map<std::string, int> freq;
    std::string word;

    for (int i = 0; i < m; i++) {
        std::cin >> word;

        for (size_t j = 0; j + n <= word.size(); j++) {
            std::string gram = word.substr(j, n);
            freq[gram]++;
        }
    }

    std::vector<std::pair<std::string, int>> grams(freq.begin(), freq.end());

    std::sort(grams.begin(), grams.end(), [](const auto& a, const auto& b) {
        if (a.second != b.second)
            return a.second > b.second;
        return a.first < b.first;
    });

    // Вывод
    for (auto& p : grams) {
        std::cout << p.first << " - " << p.second << std::endl;
    }

    return 0;
}
```