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

    if (result.size() < 4) {
        result.append(4 - result.size(), '0');
    } else if (result.size() > 4) {
        result = result.substr(0, 4);
    }

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

    for (int i = 0; i < length; ++i) {
        std::cin >> guests[i];
    }

    std::vector<int> places(length);

    for (int i = 0; i < length; ++i) {
        places[guests[i] - 1] = i + 1;
    }

    for (int i = 0; i < length; ++i) {
        std::cout << places[i] << ' ';
    }

    std::cout << std::endl;
    return 0;
}
```