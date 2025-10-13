#include "logger.h"

int main() {
    Logger a;
    Logger* b = new Logger;
    Logger* c = new Logger;
    delete b;
    delete c;
    
    return 0;
}
