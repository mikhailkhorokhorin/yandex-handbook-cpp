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