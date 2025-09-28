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
