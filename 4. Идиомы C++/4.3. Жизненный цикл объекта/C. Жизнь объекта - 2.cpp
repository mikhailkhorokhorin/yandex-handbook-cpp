#include <utility>

#include "logger.h"

int main() {
    Logger a;
    Logger b = std::move(a);

    return 0;
}
