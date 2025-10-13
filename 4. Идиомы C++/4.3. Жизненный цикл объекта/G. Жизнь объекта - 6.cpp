#include <vector>

#include "logger.h"

int main() {
    int n;
    std::cin >> n;

    std::vector<Logger*> loggers(n);

    for (int i = 0; i != n; ++i)
        loggers[i] = new Logger;

    for (int i = 0; i != n; ++i)
        delete loggers[i];

    return 0;
}
