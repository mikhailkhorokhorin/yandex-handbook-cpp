# 3.4. Адаптеры и представления

### A. Скобочная последовательность

```cpp
#include <iostream>
#include <stack>

bool matches(char open, char close) {
    return (open == '(' && close == ')') || (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

int main() {
    std::string str;
    std::cin >> str;

    std::stack<char> st;

    for (char c : str) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if (st.empty() || !matches(st.top(), c)) {
                std::cout << "NO" << std::endl;
                return 0;
            }
            st.pop();
        }
    }

    std::cout << (st.empty() ? "YES" : "NO") << std::endl;
}
```

### B. Минимум на отрезке

```cpp
#include <iostream>
#include <set>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        std::cin >> nums[i];

    std::multiset<int> window;

    for (int i = 0; i < k; ++i)
        window.insert(nums[i]);

    std::cout << *window.begin() << std::endl;

    for (int i = k; i < n; ++i) {
        window.erase(window.find(nums[i - k]));
        window.insert(nums[i]);
        std::cout << *window.begin() << std::endl;
    }

    return 0;
}
```

### C. Очередь с приоритетами

```cpp
#include <iostream>
#include <queue>
#include <string>

int main() {
    std::priority_queue<int> pq;
    std::string command;

    while (std::cin >> command) {
        if (command == "ADD") {
            int n;
            std::cin >> n;
            pq.push(n);
        } else if (command == "EXTRACT") {
            if (pq.empty()) {
                std::cout << "CANNOT" << std::endl;
            } else {
                std::cout << pq.top() << std::endl;
                pq.pop();
            }
        } else if (command == "CLEAR") {
            pq = std::priority_queue<int>();
        }
    }

    return 0;
}
```

### D. Next token

```cpp
#include <string_view>

bool NextToken(std::string_view& view, char delimiter, std::string_view& token) {
    if (view.empty())
        return false;

    size_t pos = view.find(delimiter);
    if (pos == std::string_view::npos) {
        token = view;
        view.remove_prefix(view.size());
        return true;
    }

    token = view.substr(0, pos);
    view.remove_prefix(pos + 1);
    return true;
}
```

### E. Самые частые слова

```cpp
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
    int k;
    std::cin >> k;

    std::map<std::string, int> freq;
    std::string word;

    while (std::cin >> word) {
        for (char &c : word)
            c = tolower(c);
        ++freq[word];
    }

    std::vector<std::pair<std::string, int>> v(freq.begin(), freq.end());

    sort(v.begin(), v.end(), [](const auto &a, const auto &b) {
        if (a.second != b.second)
            return a.second > b.second;
        return a.first < b.first;
    });

    for (int i = 0; i < k && i < (int)v.size(); ++i)
        std::cout << v[i].first << '\t' << v[i].second << std::endl;
}
```