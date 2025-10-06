# 3.3. Алгоритмы

### A. Удвоить вектор

```cpp
#include <vector>

template <typename T>
void Duplicate(std::vector<T>& v) {
    size_t size = v.size();

    for (size_t i = 0; i < size; ++i)
        v.push_back(v[i]);
}
```

### B. Алгоритм unique

```cpp
#include <iterator>

template <typename Iter>
Iter Unique(Iter first, Iter last) {
    if (first == last)
        return last;

    Iter result = first;
    
    for (Iter it = std::next(first); it != last; ++it) {
        if (*it != *result)
            *++result = *it;
    }
    return ++result;
}
```

### C. Алгоритм set_difference

```cpp
template <typename InIter1, typename InIter2, typename OutIter>
OutIter SetDifference(InIter1 first1, InIter1 last1, InIter2 first2, InIter2 last2, OutIter out) {
    while (first1 != last1 && first2 != last2) {
        if (*first1 < *first2)
            *out++ = *first1++;
        else if (*first1 > *first2)
            ++first2;
        else
            ++first1, ++first2;
    }
    while (first1 != last1)
        *out++ = *first1++;

    return out;
}
```

### D. Приближенный двочиный поиск

```cpp
#include <iostream>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<long long> arr1(n);
    std::vector<long long> arr2(k);

    for (int i = 0; i < n; ++i)
        std::cin >> arr1[i];
    for (int i = 0; i < k; ++i)
        std::cin >> arr2[i];

    for (auto x : arr2) {
        auto it = std::lower_bound(arr1.begin(), arr1.end(), x);

        long long best;

        if (it == arr1.begin()) {
            best = *it;
        } else if (it == arr1.end()) {
            best = arr1.back();
        } else {
            long long prev = *(it - 1);
            long long curr = *it;

            best = std::abs(curr - x) < std::abs(prev - x) ? curr : prev;
        }

        std::cout << best << std::endl;
    }

    return 0;
}
```

### E. Функция Process

```cpp
#include <algorithm>
#include <vector>

template <typename T>
void Process(const std::vector<T>& data) {
    std::vector<T> filtered;

    std::copy_if(data.begin(), data.end(), std::back_inserter(filtered),
                 [](const T& x) { return x > 0; });

    PrintResults(filtered.begin(), filtered.end());
}
```