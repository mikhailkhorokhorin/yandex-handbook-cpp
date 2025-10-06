#include <vector>

template <typename T>
void Duplicate(std::vector<T>& v) {
    size_t size = v.size();

    for (size_t i = 0; i < size; ++i)
        v.push_back(v[i]);
}
