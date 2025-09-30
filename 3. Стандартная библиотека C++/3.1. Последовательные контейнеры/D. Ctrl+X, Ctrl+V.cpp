#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> file;
    std::string line;

    while (std::getline(std::cin, line)) {
        file.push_back(line);
        if (line.empty())
            break;
    }

    int cursor = 0;
    std::string buffer = "";

    while (std::getline(std::cin, line)) {
        if (line == "Down") {
            if (cursor + 1 < (int)file.size())
                cursor++;
        } else if (line == "Up") {
            if (cursor > 0)
                cursor--;
        } else if (line == "Ctrl+X") {
            if (!file[cursor].empty()) {
                buffer = file[cursor];
                file.erase(file.begin() + cursor);
                if (cursor >= (int)file.size() && !file.empty())
                    cursor = (int)file.size() - 1;
            }
        } else if (line == "Ctrl+V") {
            if (!buffer.empty()) {
                file.insert(file.begin() + cursor, buffer);
                cursor++;
            }
        }
    }

    for (size_t i = 0; i < file.size(); i++) {
        std::cout << file[i] << std::endl;
    }

    return 0;
}
