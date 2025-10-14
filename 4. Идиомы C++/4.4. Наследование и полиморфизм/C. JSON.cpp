#include <iostream>
#include <string>
#include <vector>

class Serializer {
   public:
    virtual void BeginArray() = 0;
    virtual void EndArray() = 0;
    virtual void AddArrayItem(const std::string& value) = 0;
    virtual ~Serializer() = default;
};

class JsonSerializer : public Serializer {
   private:
    std::vector<int> counts_;

    void tryPrintComma() {
        if (!counts_.empty() && counts_.back() > 0) {
            std::cout << ',';
        }
    }

   public:
    void BeginArray() override {
        if (!counts_.empty())
            tryPrintComma();

        std::cout << '[';
        counts_.push_back(0);
    }

    void EndArray() override {
        std::cout << ']';

        if (!counts_.empty()) {
            counts_.pop_back();

            if (!counts_.empty())
                ++counts_.back();
        }
    }

    void AddArrayItem(const std::string& value) override {
        if (!counts_.empty()) {
            tryPrintComma();

            std::cout << '"' << value << '"';
            ++counts_.back();
        }
    }

    ~JsonSerializer() override = default;
};
