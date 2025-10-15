# 4.4. Обработка исключений

### A. Адреса

```cpp
#include <iostream>
#include <string>

#include "address.h"

int main() {
    std::string line;

    while (getline(std::cin, line)) {
        try {
            Address address;
            Parse(line, &address);
            Unify(&address);
            std::cout << Format(address) << std::endl;
        } catch (...) {
            std::cout << "exception" << std::endl;
        }
    }
}
```

### B. Retry

```cpp
#include <exception>
#include <functional>
#include <optional>

template <typename Result, typename Exception = std::exception>
std::optional<Result> DoWithRetry(std::function<Result()> func, int retryCount, int sleepTime,
                                  bool throwLast) {
    for (int i = 0; i <= retryCount; ++i) {
        try {
            return func();
        } catch (const Exception& e) {
            if (i == retryCount) {
                if (throwLast)
                    throw;
            } else {
                Sleep(sleepTime);
            }
        }
    }

    return {};
}
```

### C. BiMap

```cpp
#include <list>
#include <map>
#include <optional>
#include <stdexcept>

template <typename Key1, typename Key2, typename Value>
class BiMap {
   private:
    std::map<Key1, Value*> map1_;
    std::map<Key2, Value*> map2_;
    std::list<Value> values_;

   public:
    void Insert(const std::optional<Key1>& key1, const std::optional<Key2>& key2,
                const Value& value) {
        if (!key1 && !key2)
            throw std::invalid_argument("Keys are empty");

        if (key1 && map1_.count(*key1))
            throw std::invalid_argument("Key already exists");

        if (key2 && map2_.count(*key2))
            throw std::invalid_argument("Key already exists");

        values_.push_back(value);
        Value* ptr = &values_.back();

        if (key1)
            map1_[*key1] = ptr;

        if (key2)
            map2_[*key2] = ptr;
    }

    Value& GetByPrimaryKey(const Key1& key) {
        return *map1_.at(key);
    }

    const Value& GetByPrimaryKey(const Key1& key) const {
        return *map1_.at(key);
    }

    Value& GetBySecondaryKey(const Key2& key) {
        return *map2_.at(key);
    }

    const Value& GetBySecondaryKey(const Key2& key) const {
        return *map2_.at(key);
    }
};
```

### D. LoggerGuard

```cpp
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
```