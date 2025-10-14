# 4.4. Наследование и полиморфизм

### A. Периметр Фигуры

```cpp
class Figure {
   public:
    virtual int Perimeter() const = 0;
    virtual ~Figure() = default;
};

class Triangle : public Figure {
   private:
    int a_, b_, c_;

   public:
    Triangle(int a, int b, int c) : a_(a), b_(b), c_(c) {
    }

    int Perimeter() const override {
        return a_ + b_ + c_;
    }
};

class Rectangle : public Figure {
   private:
    int a_, b_;

   public:
    Rectangle(int a, int b) : a_(a), b_(b) {
    }

    int Perimeter() const override {
        return 2 * (a_ + b_);
    }
};s
```

### B. Notifications

```cpp
#include <string>

class NotifierBase {
   public:
    virtual void Notify(const std::string& message) const = 0;
    virtual ~NotifierBase() = default;
};

class SmsNotifier : public NotifierBase {
   private:
    std::string number_;

   public:
    explicit SmsNotifier(const std::string& number) : number_(number) {
    }

    void Notify(const std::string& message) const override {
        SendSms(number_, message);
    }
};

class EmailNotifier : public NotifierBase {
   private:
    std::string email_;

   public:
    explicit EmailNotifier(const std::string& email) : email_(email) {
    }

    void Notify(const std::string& message) const override {
        SendEmail(email_, message);
    }
};
```

### C. JSON

```cpp
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
```

### D. AdvancedVector

```cpp
#include <cstdint>
#include <vector>

template <typename T>
class AdvancedVector : public std::vector<T> {
   public:
    AdvancedVector() = default;

    template <typename Iter>
    AdvancedVector(Iter first, Iter last) : std::vector<T>(first, last) {
    }

    const T& operator[](std::int64_t i) const {
        if (i < 0)
            i += this->size();

        return this->at(i);
    }

    T& operator[](std::int64_t i) {
        if (i < 0)
            i += this->size();

        return this->at(i);
    }
};
```

### E. Жизнь объекта с наследованием

```cpp
class B : public A {
   public:
    B() : A(42) {
    }
    void foo() const override {
    }
};
```
