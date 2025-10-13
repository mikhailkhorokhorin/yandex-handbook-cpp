#include <vector>

#include "logger.h"

int main() {
    int n;
    std::cin >> n;

    std::vector<Logger> loggers(n);

    for (int i = 0; i != n; ++i)
        loggers.pop_back();

    return 0;
}
