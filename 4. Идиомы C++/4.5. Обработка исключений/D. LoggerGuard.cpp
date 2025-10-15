#include <iostream>
#include <string>

class LoggerGuard {
   private:
    std::string message_;
    std::ostream& out_;

   public:
    LoggerGuard(const std::string& message, std::ostream& out = std::cout)
        : message_(message), out_(out) {
    }

    ~LoggerGuard() {
        out_ << message_ << std::endl;
    }
};
