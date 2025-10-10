#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

int main() {
    std::set<std::string> dirs;
    std::string path;

    while (std::getline(std::cin, path)) {
        std::vector<std::string> parts;
        std::string item;

        std::stringstream ss(path);

        while (std::getline(ss, item, '/'))
            parts.push_back(item);

        std::string cur = "/";
        dirs.insert(cur);

        for (size_t i = 1; i + 1 < parts.size(); i++) {
            cur += parts[i] + "/";
            dirs.insert(cur);
        }
    }

    for (auto& dir : dirs)
        std::cout << dir << std::endl;

    return 0;
}