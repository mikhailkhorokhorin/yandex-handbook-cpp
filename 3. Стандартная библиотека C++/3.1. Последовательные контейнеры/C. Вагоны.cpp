#include <deque>
#include <iostream>
#include <string>

void MakeTrain() {
    std::deque<int> train;
    std::string command;

    while (std::cin >> command) {
        int m;
        std::cin >> m;

        if (command == "+left") {
            train.push_front(m);
        } else if (command == "+right") {
            train.push_back(m);
        } else if (command == "-left") {
            if (m >= (int)train.size())
                train.clear();
            else
                train.erase(train.begin(), train.begin() + m);

        } else if (command == "-right") {
            if (m >= (int)train.size())
                train.clear();
            else
                train.erase(train.end() - m, train.end());
        }
    }

    for (size_t i = 0; i < train.size(); ++i) {
        if (i > 0)
            std::cout << ' ';
        std::cout << train[i];
    }
    
    std::cout << std::endl;
}