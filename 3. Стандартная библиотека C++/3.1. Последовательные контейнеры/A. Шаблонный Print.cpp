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