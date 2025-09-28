# 2.7. Функции

### A. ArgMax в матрице

```cpp
#include <vector>

std::pair<size_t, size_t> MatrixArgMax(const std::vector<std::vector<int>>& matrix) {
    std::pair<size_t, size_t> maxPos(0, 0);

    size_t n = matrix.size();
    size_t k = matrix[0].size();

    int maxNum = matrix[0][0];

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < k; ++j) {
            if (matrix[i][j] > maxNum) {
                maxNum = matrix[i][j];
                maxPos = {i, j};
            }
        }
    }

    return maxPos;
}
```

### B. Общий префикс

```cpp
#include <algorithm>
#include <string>
#include <vector>

std::string CommonPrefix(const std::vector<std::string>& words) {
    if (words.empty())
        return "";

    std::string maxPrefix = *std::min_element(
        words.begin(), words.end(),
        [](const std::string& a, const std::string& b) { return a.size() < b.size(); });

    for (const std::string& word : words) {
        size_t prefixLength = 0;

        while (prefixLength < maxPrefix.size() && maxPrefix[prefixLength] == word[prefixLength])
            ++prefixLength;

        maxPrefix = maxPrefix.substr(0, prefixLength);
        if (maxPrefix.empty())
            break;
    }

    return maxPrefix;
}
```

### С. Функция Split

```cpp
#include <string>
#include <vector>

std::vector<std::string> Split(const std::string& str, char delimiter) {
    std::vector<std::string> result;

    size_t ptr = 0;

    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] == delimiter) {
            result.push_back(str.substr(ptr, i - ptr));
            ptr = i + 1;
        }
    }

    result.push_back(str.substr(ptr, str.length() - ptr));

    return result;
}
```

### D. Функция Join

```cpp
#include <string>
#include <vector>

std::string Join(const std::vector<std::string>& tokens, char delimiter) {
    if (tokens.empty())
        return "";

    if (tokens.size() == 1)
        return tokens[0];

    std::string result = tokens[0];

    for (size_t i = 1; i < tokens.size(); ++i) {
        result += delimiter;
        result += tokens[i];
    }

    return result;
}
```

### E. Транспонировать матрицу

```cpp
#include <vector>

std::vector<std::vector<int>> Transpose(const std::vector<std::vector<int>>& matrix) {
    size_t n = matrix.size();
    size_t m = matrix[0].size();

    std::vector<std::vector<int>> result(m, std::vector<int>(n, 0));

    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < m; ++j)
            result[j][i] = matrix[i][j];

    return result;
}
```

### F. Сортировка точек

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int len;
    std::cin >> len;

    std::vector<std::pair<int, int>> points(len, {0, 0});
    for (int i = 0; i < len; ++i)
        std::cin >> points[i].first >> points[i].second;

    std::sort(points.begin(), points.end(), [](const auto& a, const auto& b) {
        long long da = 1LL * a.first * a.first + 1LL * a.second * a.second;
        long long db = 1LL * b.first * b.first + 1LL * b.second * b.second;
        if (da == db) {
            if (a.first == b.first)
                return a.second < b.second;
            return a.first < b.first;
        }
        return da < db;
    });

    for (const std::pair<int, int>& p : points)
        std::cout << p.first << " " << p.second << std::endl;

    return 0;
}
```