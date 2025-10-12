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
