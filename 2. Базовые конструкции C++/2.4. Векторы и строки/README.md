# 2.4. Векторы и строки

### A. Пароли

```cpp
#include <iostream>
#include <string>

int main() {
    std::string password;
    std::cin >> password;

    if (8 > password.size() || password.size() > 14) {
        std::cout << "NO" << std::endl;
        return 0;
    }

    bool hasUpper = false, hasLower = false, hasDigit = false, hasOther = false;

    for (char ch : password) {
        if (33 > ch || ch > 126) {
            std::cout << "NO" << std::endl;
            return 0;
        }

        if ('A' <= ch && ch <= 'Z')
            hasUpper = true;
        else if ('a' <= ch && ch <= 'z')
            hasLower = true;
        else if ('0' <= ch && ch <= '9')
            hasDigit = true;
        else
            hasOther = true;
    }

    std::cout << ((hasUpper + hasLower + hasDigit + hasOther) >= 3 ? "YES" : "NO");
    return 0;
}
```

### B. Soundex

```cpp
#include <iostream>
#include <string>

char encodeLetter(char ch) {
    if (ch == 'b' || ch == 'f' || ch == 'p' || ch == 'v')
        return '1';
    if (ch == 'c' || ch == 'g' || ch == 'j' || ch == 'k' || ch == 'q' || ch == 's' || ch == 'x' ||
        ch == 'z')
        return '2';
    if (ch == 'd' || ch == 't')
        return '3';
    if (ch == 'l')
        return '4';
    if (ch == 'm' || ch == 'n')
        return '5';
    if (ch == 'r')
        return '6';
    return '\0';
}

int main() {
    std::string word;
    std::cin >> word;

    std::string result;
    result += word[0];

    char lastCode = '\0';

    for (size_t i = 1; i < word.size(); ++i) {
        char code = encodeLetter(word[i]);

        if (code != '\0' && code != lastCode) {
            result += code;
            lastCode = code;
        }
    }

    if (result.size() < 4)
        result.append(4 - result.size(), '0');
    else if (result.size() > 4)
        result = result.substr(0, 4);

    std::cout << result << std::endl;
}
```

### C. Обратная перестановка

```cpp
#include <iostream>
#include <vector>

int main() {
    int length = 0;
    std::cin >> length;

    std::vector<int> guests(length);

    for (int i = 0; i < length; ++i)
        std::cin >> guests[i];

    std::vector<int> places(length);

    for (int i = 0; i < length; ++i)
        places[guests[i] - 1] = i + 1;

    for (int i = 0; i < length; ++i)
        std::cout << places[i] << ' ';

    std::cout << std::endl;
    return 0;
}
```

### D. Сортировка по убыванию

```cpp
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> words;

    std::string word;
    while (std::getline(std::cin, word))
        words.push_back(word);

    std::sort(words.rbegin(), words.rend());

    for (std::string word : words)
        std::cout << word << std::endl;

    return 0;
}
```

### E. Палиндромы

```cpp
#include <algorithm>
#include <iostream>
#include <string>

int main() {
    std::string word;
    std::getline(std::cin, word);

    word.erase(std::remove(word.begin(), word.end(), ' '), word.end());

    std::string reversed = word;
    std::reverse(reversed.begin(), reversed.end());

    std::cout << (word == reversed ? "YES" : "NO") << std::endl;

    return 0;
}
```

### F. Сапёр

```cpp
#include <iostream>
#include <vector>

int main() {
    int m, n, k;
    std::cin >> m >> n >> k;

    std::vector<std::vector<int>> field(m, std::vector<int>(n, 0));
    std::vector<std::pair<int, int>> mines(k);

    for (int i = 0; i < k; ++i) {
        int x, y;
        std::cin >> x >> y;

        x--;
        y--;

        mines[i] = {x, y};
        field[x][y] = -1;
    }

    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (auto [x, y] : mines) {
        for (int d = 0; d < 8; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && field[nx][ny] != -1) {
                field[nx][ny]++;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (field[i][j] == -1)
                std::cout << "*";
            else
                std::cout << field[i][j];

            if (j + 1 < n)
                std::cout << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
```
