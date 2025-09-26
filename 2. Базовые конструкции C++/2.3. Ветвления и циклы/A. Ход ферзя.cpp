#include <iostream>

int main() {
    int startx, startY, endX, endY;
    std::cin >> startx >> startY >> endX >> endY;

    bool condition = startx == endX || startY == endY || abs(startx - endX) == abs(startY - endY);

    std::cout << (condition ? "YES" : "NO") << std::endl;

    return 0;
}