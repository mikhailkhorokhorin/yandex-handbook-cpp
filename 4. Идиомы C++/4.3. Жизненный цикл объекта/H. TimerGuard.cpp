#include <chrono>
#include <iostream>
#include <string>

class TimerGuard {
   private:
    std::string message_;
    std::ostream& out_;
    std::chrono::high_resolution_clock::time_point start_;

   public:
    TimerGuard(std::string message = "", std::ostream& out = std::cout)
        : message_(std::move(message)),
          out_(out),
          start_(std::chrono::high_resolution_clock::now()) {
    }

    ~TimerGuard() {
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start_;
        out_ << message_ << diff.count() << std::endl;
    }
};
