#include <algorithm>
#include <iostream>
#include <string>

int main() {
    std::string word;
    std::getline(std::cin, word);

    word.erase(std::remove(word.begin(), word.end(), ' '), word.end());

    std::string reversed = word;
    std::reverse(reversed.begin(), reversed.end());

    std::cout << (word == reversed ? "YES" : "NO") << std::endl;

    return 0;
}