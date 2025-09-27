#include <iostream>
#include <string>

int main() {
    std::string password;
    std::cin >> password;

    if (8 > password.size() || password.size() > 14) {
        std::cout << "NO" << std::endl;
        return 0;
    }

    bool hasUpper = false, hasLower = false, hasDigit = false, hasOther = false;

    for (char ch : password) {
        if (33 > ch || ch > 126) {
            std::cout << "NO" << std::endl;
            return 0;
        }

        if ('A' <= ch && ch <= 'Z')
            hasUpper = true;
        else if ('a' <= ch && ch <= 'z')
            hasLower = true;
        else if ('0' <= ch && ch <= '9')
            hasDigit = true;
        else
            hasOther = true;
    }

    std::cout << ((hasUpper + hasLower + hasDigit + hasOther) >= 3 ? "YES" : "NO");
    return 0;
}