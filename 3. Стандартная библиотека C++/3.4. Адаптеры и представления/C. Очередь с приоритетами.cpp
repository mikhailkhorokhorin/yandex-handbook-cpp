#include <iostream>
#include <queue>
#include <string>

int main() {
    std::priority_queue<int> pq;
    std::string command;

    while (std::cin >> command) {
        if (command == "ADD") {
            int n;
            std::cin >> n;
            pq.push(n);
        } else if (command == "EXTRACT") {
            if (pq.empty()) {
                std::cout << "CANNOT" << std::endl;
            } else {
                std::cout << pq.top() << std::endl;
                pq.pop();
            }
        } else if (command == "CLEAR") {
            pq = std::priority_queue<int>();
        }
    }

    return 0;
}
