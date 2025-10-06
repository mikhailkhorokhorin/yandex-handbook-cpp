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
