#include <iostream>
#include <string>

char encodeLetter(char ch) {
    if (ch == 'b' || ch == 'f' || ch == 'p' || ch == 'v')
        return '1';
    if (ch == 'c' || ch == 'g' || ch == 'j' || ch == 'k' || ch == 'q' || ch == 's' || ch == 'x' ||
        ch == 'z')
        return '2';
    if (ch == 'd' || ch == 't')
        return '3';
    if (ch == 'l')
        return '4';
    if (ch == 'm' || ch == 'n')
        return '5';
    if (ch == 'r')
        return '6';
    return '\0';
}

int main() {
    std::string word;
    std::cin >> word;

    std::string result;
    result += word[0];

    char lastCode = '\0';

    for (size_t i = 1; i < word.size(); ++i) {
        char code = encodeLetter(word[i]);

        if (code != '\0' && code != lastCode) {
            result += code;
            lastCode = code;
        }
    }

    if (result.size() < 4)
        result.append(4 - result.size(), '0');
    else if (result.size() > 4)
        result = result.substr(0, 4);

    std::cout << result << std::endl;
}
