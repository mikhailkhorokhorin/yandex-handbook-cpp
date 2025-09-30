#include <deque>
#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;

    std::deque<std::string> works;

    for (int i = 0; i < n; ++i) {
        std::string Surname, position;
        std::cin >> Surname >> position;

        if (position == "top")
            works.push_front(Surname);
        else
            works.push_back(Surname);
    }

    int m;
    std::cin >> m;

    for (int i = 0; i < m; ++i) {
        int x;
        std::cin >> x;

        std::cout << works[x - 1] << std::endl;
    }
    return 0;
}