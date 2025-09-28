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
