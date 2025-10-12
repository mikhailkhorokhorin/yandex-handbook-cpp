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
