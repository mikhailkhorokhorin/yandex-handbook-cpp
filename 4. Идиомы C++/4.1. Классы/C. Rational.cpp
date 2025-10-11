#include <numeric>

class Rational {
   private:
    int numeraror_;
    int denominator_;

    void normalize() {
        if (denominator_ < 0) {
            numeraror_ = -numeraror_;
            denominator_ = -denominator_;
        }

        int g = std::gcd(numeraror_, denominator_);

        numeraror_ /= g;
        denominator_ /= g;
    }

   public:
    Rational(int numeraror = 0, int dennominator = 1)
        : numeraror_(numeraror), denominator_(dennominator) {
        normalize();
    }

    int Numerator() const {
        return numeraror_;
    }

    int Denominator() const {
        return denominator_;
    }

    friend Rational operator+(int number, const Rational& rational) {
        return Rational(number) + rational;
    }

    friend Rational operator-(int number, const Rational& rational) {
        return Rational(number) - rational;
    }

    friend Rational operator*(int number, const Rational& rational) {
        return Rational(number) * rational;
    }

    friend Rational operator/(int number, const Rational& rational) {
        return Rational(number) / rational;
    }

    Rational operator+(const Rational& other) const {
        return Rational(numeraror_ * other.denominator_ + other.numeraror_ * denominator_,
                        denominator_ * other.denominator_);
    }

    Rational operator-(const Rational& other) const {
        return Rational(numeraror_ * other.denominator_ - other.numeraror_ * denominator_,
                        denominator_ * other.denominator_);
    }

    Rational operator*(const Rational& other) const {
        return Rational(numeraror_ * other.numeraror_, denominator_ * other.denominator_);
    }

    Rational operator/(const Rational& other) const {
        return Rational(numeraror_ * other.denominator_, denominator_ * other.numeraror_);
    }

    Rational& operator+=(const Rational& other) {
        return *this = *this + other;
    }

    Rational& operator-=(const Rational& other) {
        return *this = *this - other;
    }

    Rational& operator*=(const Rational& other) {
        return *this = *this * other;
    }

    Rational& operator/=(const Rational& other) {
        return *this = *this / other;
    }

    Rational operator+() const {
        return *this;
    }

    Rational operator-() const {
        return Rational(-numeraror_, denominator_);
    }

    bool operator==(const Rational& other) const {
        return numeraror_ == other.numeraror_ && denominator_ == other.denominator_;
    }

    bool operator!=(const Rational& other) const {
        return !(*this == other);
    }
};
