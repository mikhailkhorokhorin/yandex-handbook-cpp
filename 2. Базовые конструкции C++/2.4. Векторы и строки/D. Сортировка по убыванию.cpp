#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> words;

    std::string word;
    while (std::getline(std::cin, word))
        words.push_back(word);

    std::sort(words.rbegin(), words.rend());

    for (std::string word : words)
        std::cout << word << std::endl;

    return 0;
}