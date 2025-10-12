# 4.2. Шаблонные классы

### A. Table

```cpp
#include <vector>

template <typename T>
class Table {
   private:
    std::vector<std::vector<T>> data_;

   public:
    Table(size_t rows, size_t cols) : data_(rows, std::vector<T>(cols)) {
    }

    std::vector<T>& operator[](size_t i) {
        return data_[i];
    }

    const std::vector<T>& operator[](size_t i) const {
        return data_[i];
    }

    void resize(size_t new_rows, size_t new_cols) {
        data_.resize(new_rows);
        for (auto& row : data_)
            row.resize(new_cols);
    }

    std::pair<size_t, size_t> size() const {
        if (data_.empty())
            return {0, 0};
        return {data_.size(), data_[0].size()};
    }
};
```

### B. Queue

```cpp
#include <deque>

template <typename T, typename Container = std::deque<T>>
class Queue {
   private:
    Container data_;

   public:
    Queue() = default;

    T& front() {
        return data_.front();
    }

    const T& front() const {
        return data_.front();
    }

    void push(const T& value) {
        data_.push_back(value);
    }

    void pop() {
        data_.pop_front();
    }

    bool empty() const {
        return data_.empty();
    }

    size_t size() const {
        return data_.size();
    }

    bool operator==(const Queue& other) const {
        return data_ == other.data_;
    }

    bool operator!=(const Queue& other) const {
        return !(*this == other);
    }
};
```

### C. Key-Value storage

```cpp
template <typename Key, typename Value>
bool KeyValueStorage<Key, Value>::Find(const Key& key, Value* const value) const {
    auto iter = data.find(key);

    if (iter == data.end())
        return false;

    if (value != nullptr)
        *value = iter->second;

    return true;
}
```

### D. Deque

```cpp
#include <stdexcept>
#include <vector>

template <typename T>
class Deque {
   private:
    std::vector<T> head_;
    std::vector<T> tail_;

   public:
    bool Empty() const {
        return head_.empty() && tail_.empty();
    }

    size_t Size() const {
        return head_.size() + tail_.size();
    }

    void Clear() {
        head_.clear();
        tail_.clear();
    }

    const T& operator[](size_t i) const {
        if (i < head_.size())
            return head_[head_.size() - i - 1];

        return tail_[i - head_.size()];
    }

    T& operator[](size_t i) {
        if (i < head_.size())
            return head_[head_.size() - i - 1];

        return tail_[i - head_.size()];
    }

    const T& At(size_t i) const {
        if (i >= Size())
            throw std::out_of_range("Index out of range");

        return (*this)[i];
    }

    T& At(size_t i) {
        if (i >= Size())
            throw std::out_of_range("Index out of range");

        return (*this)[i];
    }

    const T& Front() const {
        if (!head_.empty())
            return head_.back();

        return tail_.front();
    }

    T& Front() {
        if (!head_.empty())
            return head_.back();

        return tail_.front();
    }

    const T& Back() const {
        if (!tail_.empty())
            return tail_.back();

        return head_.front();
    }

    T& Back() {
        if (!tail_.empty())
            return tail_.back();

        return head_.front();
    }

    void PushFront(const T& elem) {
        head_.push_back(elem);
    }

    void PushBack(const T& elem) {
        tail_.push_back(elem);
    }
};
```

### E. MathVector

```cpp
#include <iostream>
#include <vector>

template <typename T>
class MathVector {
   private:
    std::vector<T> data_;

   public:
    MathVector(size_t n) : data_(n) {
    }

    template <typename Iter>
    MathVector(Iter first, Iter last) : data_(first, last) {
    }

    size_t Dimension() const {
        return data_.size();
    }

    T& operator[](size_t i) {
        return data_[i];
    }

    const T& operator[](size_t i) const {
        return data_[i];
    }

    MathVector<T>& operator+=(const MathVector<T>& other) {
        for (size_t i = 0; i < Dimension(); ++i)
            data_[i] += other[i];

        return *this;
    }

    MathVector<T> operator+(const MathVector<T>& other) const {
        MathVector<T> result = *this;
        result += other;
        return result;
    }
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const MathVector<T>& v) {
    out << '(';
    for (size_t i = 0; i < v.Dimension(); ++i) {
        if (i > 0)
            out << ", ";
        out << v[i];
    }
    out << ')';
    return out;
}

template <typename T>
MathVector<T>& operator*=(MathVector<T>& v, const T& scalar) {
    for (size_t i = 0; i < v.Dimension(); ++i)
        v[i] *= scalar;

    return v;
}

template <typename T>
MathVector<T> operator*(const MathVector<T>& v, const T& scalar) {
    MathVector<T> tmp(v);
    tmp *= scalar;
    return tmp;
}

template <typename T>
MathVector<T> operator*(const T& scalar, const MathVector<T>& v) {
    return v * scalar;
}
```

### F. Многопоточность

```cpp
#include <iostream>
#include <vector>

template <typename T>
class Polynomial {
   private:
    std::vector<T> coefficients;

    void trim() {
        while (!coefficients.empty() && coefficients.back() == T{})
            coefficients.pop_back();
    }

   public:
    using ConstIterator = typename std::vector<T>::const_iterator;

    Polynomial() = default;

    Polynomial(const T& value) : coefficients{value} {
        trim();
    }
    
    Polynomial(const std::vector<T>& coeffs) : coefficients(coeffs) {
        trim();
    }
    
    template <typename Iter>
    Polynomial(Iter first, Iter last) : coefficients(first, last) {
        trim();
    }

    T operator[](size_t power) const {
        return power < coefficients.size() ? coefficients[power] : T{};
    }

    int Degree() const {
        return coefficients.empty() ? -1 : static_cast<int>(coefficients.size()) - 1;
    }

    Polynomial& operator+=(const Polynomial& other) {
        if (other.Degree() > Degree())
            coefficients.resize(other.Degree() + 1);

        for (size_t i = 0; i < other.coefficients.size(); ++i)
            coefficients[i] += other.coefficients[i];

        trim();
        return *this;
    }

    Polynomial& operator-=(const Polynomial& other) {
        if (other.Degree() > Degree())
            coefficients.resize(other.Degree() + 1);

        for (size_t i = 0; i < other.coefficients.size(); ++i)
            coefficients[i] -= other.coefficients[i];

        trim();
        return *this;
    }

    Polynomial& operator*=(const Polynomial& other) {
        if (Degree() == -1 || other.Degree() == -1) {
            coefficients.clear();
            return *this;
        }

        std::vector<T> result(Degree() + other.Degree() + 1);
        for (size_t i = 0; i < coefficients.size(); ++i)
            for (size_t j = 0; j < other.coefficients.size(); ++j)
                result[i + j] += coefficients[i] * other.coefficients[j];

        coefficients = std::move(result);
        trim();
        return *this;
    }

    Polynomial& operator+=(const T& scalar) {
        if (coefficients.empty())
            coefficients.push_back(scalar);
        else
            coefficients[0] += scalar;

        trim();
        return *this;
    }

    Polynomial& operator-=(const T& scalar) {
        if (coefficients.empty())
            coefficients.push_back(-scalar);
        else
            coefficients[0] -= scalar;

        trim();
        return *this;
    }

    Polynomial& operator*=(const T& scalar) {
        for (auto& c : coefficients)
            c *= scalar;

        trim();
        return *this;
    }

    friend Polynomial operator+(Polynomial lhs, const Polynomial& rhs) {
        return lhs += rhs;
    }

    friend Polynomial operator-(Polynomial lhs, const Polynomial& rhs) {
        return lhs -= rhs;
    }

    friend Polynomial operator*(Polynomial lhs, const Polynomial& rhs) {
        return lhs *= rhs;
    }

    friend Polynomial operator+(Polynomial lhs, const T& rhs) {
        return lhs += rhs;
    }

    friend Polynomial operator-(Polynomial lhs, const T& rhs) {
        return lhs -= rhs;
    }

    friend Polynomial operator*(Polynomial lhs, const T& rhs) {
        return lhs *= rhs;
    }

    friend Polynomial operator+(const T& lhs, Polynomial rhs) {
        return rhs += lhs;
    }

    friend Polynomial operator-(const T& lhs, Polynomial rhs) {
        return (rhs *= T{-1}) += lhs;
    }

    friend Polynomial operator*(const T& lhs, Polynomial rhs) {
        return rhs *= lhs;
    }

    friend bool operator==(const Polynomial& lhs, const Polynomial& rhs) {
        return lhs.coefficients == rhs.coefficients;
    }

    friend bool operator!=(const Polynomial& lhs, const Polynomial& rhs) {
        return !(lhs == rhs);
    }

    T operator()(const T& x) const {
        T result{};
        for (auto it = coefficients.rbegin(); it != coefficients.rend(); ++it)
            result = result * x + *it;

        return result;
    }

    ConstIterator begin() const {
        return coefficients.cbegin();
    }

    ConstIterator end() const {
        return coefficients.cend();
    }

    friend std::ostream& operator<<(std::ostream& out, const Polynomial& poly) {
        for (int i = poly.Degree(); i >= 0; --i) {
            out << poly[i];
            if (i != 0)
                out << ' ';
        }

        return out;
    }
};
```