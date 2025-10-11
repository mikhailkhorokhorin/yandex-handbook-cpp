# 4.1. Классы

### A. Дата

```cpp
#include <array>

class Date {
   private:
    int day_;
    int month_;
    int year_;

    Date(int totalDays) {
        int year = 1970;
        while (true) {
            int yearDays = isLeap(year) ? 366 : 365;

            if (totalDays >= yearDays) {
                totalDays -= yearDays;
                ++year;
            } else
                break;
        }

        int month = 1;
        while (true) {
            int monthDays = getDaysInMonth(month, year);

            if (totalDays >= monthDays) {
                totalDays -= monthDays;
                ++month;
            } else
                break;
        }

        day_ = totalDays + 1;
        month_ = month;
        year_ = year;
    }

    static bool isLeap(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    static int getDaysInMonth(int month, int year) {
        static const std::array<int, 12> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        return (month == 2 && isLeap(year)) ? 29 : days[month - 1];
    }

    static bool isValid(int day, int month, int year) {
        return year >= 1970 && year <= 2099 && month >= 1 && month <= 12 && day >= 1 &&
               day <= getDaysInMonth(month, year);
    }

    static int countDays(int day, int month, int year) {
        int total = 0;
        for (int y = 1970; y < year; ++y)
            total += isLeap(y) ? 366 : 365;
        for (int m = 1; m < month; ++m)
            total += getDaysInMonth(m, year);
        return total + day - 1;
    }

   public:
    Date(int day, int month, int year) {
        if (isValid(day, month, year)) {
            day_ = day;
            month_ = month;
            year_ = year;
        } else {
            day_ = 1;
            month_ = 1;
            year_ = 1970;
        }
    }

    int GetDay() const {
        return day_;
    }

    int GetMonth() const {
        return month_;
    }

    int GetYear() const {
        return year_;
    }

    Date operator+(int n) const {
        int days = countDays(day_, month_, year_) + n;
        if (days < 0)
            days = 0;
        return Date(days);
    }

    Date operator-(int n) const {
        int days = countDays(day_, month_, year_) - n;
        if (days < 0)
            days = 0;
        return Date(days);
    }

    int operator-(const Date& other) const {
        return countDays(day_, month_, year_) - countDays(other.day_, other.month_, other.year_);
    }
};
```

### B. Дата - 2

```cpp
#include <array>

class Date {
   private:
    int days_;

    Date(int days) {
        days_ = (days < 0 ? 0 : days);
    }

    static bool isLeap(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    static int getDaysInMonth(int month, int year) {
        static const std::array<int, 12> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        return (month == 2 && isLeap(year)) ? 29 : days[month - 1];
    }

    static bool isValid(int day, int month, int year) {
        return year >= 1970 && year <= 2099 && month >= 1 && month <= 12 && day >= 1 &&
               day <= getDaysInMonth(month, year);
    }

    static int countDays(int day, int month, int year) {
        int total = 0;
        for (int y = 1970; y < year; ++y)
            total += isLeap(y) ? 366 : 365;
        for (int m = 1; m < month; ++m)
            total += getDaysInMonth(m, year);
        return total + day - 1;
    }

    static void fromDays(int total, int& day, int& month, int& year) {
        year = 1970;
        while (true) {
            int yearDays = isLeap(year) ? 366 : 365;
            if (total >= yearDays) {
                total -= yearDays;
                ++year;
            } else
                break;
        }
        month = 1;
        while (true) {
            int monthDays = getDaysInMonth(month, year);
            if (total >= monthDays) {
                total -= monthDays;
                ++month;
            } else
                break;
        }
        day = total + 1;
    }

   public:
    Date(int day, int month, int year) {
        days_ = isValid(day, month, year) ? countDays(day, month, year) : 0;
    }

    int GetDay() const {
        int day, month, year;
        fromDays(days_, day, month, year);
        return day;
    }

    int GetMonth() const {
        int day, month, year;
        fromDays(days_, day, month, year);
        return month;
    }
    
    int GetYear() const {
        int day, month, year;
        fromDays(days_, day, month, year);
        return year;
    }

    Date operator+(int n) const {
        return Date(days_ + n);
    }

    Date operator-(int n) const {
        return Date(days_ - n);
    }

    int operator-(const Date& o) const {
        return days_ - o.days_;
    }
};
```

### C. Rational 

```cpp
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
```

### D. Tree

```cpp
bool Tree::Has(const std::vector<std::string>& path) const {
    const Node* node = &root;

    for (const auto& key : path) {
        auto iter = node->children.find(key);

        if (iter == node->children.end())
            return false;

        node = &iter->second;
    }
    return true;
}

void Tree::Insert(const std::vector<std::string>& path) {
    Node* node = &root;

    for (const auto& key : path) 
        node = &node->children[key];
    
}

void Tree::Delete(const std::vector<std::string>& path) {
    Node* node = &root;
    std::vector<Node*> nodes;
    std::vector<std::string> keys;

    nodes.push_back(node);
    for (const auto& key : path) {
        auto iter = node->children.find(key);

        if (iter == node->children.end())
            return;
        node = &iter->second;
        
        nodes.push_back(node);
        keys.push_back(key);
    }

    Node* parent = nodes[nodes.size() - 2];
    parent->children.erase(keys.back());
}
```

### E. Крестики-нолики

```cpp
#include <iostream>
#include <vector>

class TicTacToe {
   public:
    const size_t N;
    const size_t K;

   private:
    std::vector<std::vector<int>> Table;
    int currentPlayer;

   public:
    TicTacToe(size_t n, size_t k) : N(n), K(k), currentPlayer(1) {
        Table.assign(N, std::vector<int>(N, 0));
    }

    int operator()(size_t i, size_t j) const {
        return Table[i][j];
    }

    int GetCurrentPlayer() const {
        return currentPlayer;
    }

    bool Set(size_t i, size_t j) {
        Table[i][j] = currentPlayer;
        currentPlayer = currentPlayer % 2 + 1;
        bool wins =
            CheckRow(i, j) || CheckColumn(i, j) || CheckDiagonal1(i, j) || CheckDiagonal2(i, j);
        return wins;
    }

   private:
    bool CheckRow(size_t i, size_t j) const {
        size_t d1 = 0;
        while (d1 <= j && Table[i][j - d1] == Table[i][j])
            ++d1;

        size_t d2 = 0;
        while (j + d2 < N && Table[i][j + d2] == Table[i][j])
            ++d2;

        return d1 + d2 > K;
    }

    bool CheckColumn(size_t i, size_t j) const {
        int val = Table[i][j];

        size_t count = 1;
        for (size_t ii = i; ii > 0 && Table[ii - 1][j] == val; --ii)
            ++count;

        for (size_t ii = i + 1; ii < N && Table[ii][j] == val; ++ii)
            ++count;

        return count >= K;
    }

    size_t CountInDirection(size_t i, size_t j, int di, int dj) const {
        int val = Table[i][j];
        size_t count = 0;
        int x = static_cast<int>(i);
        int y = static_cast<int>(j);
        while (x >= 0 && y >= 0 && x < static_cast<int>(N) && y < static_cast<int>(N) &&
               Table[x][y] == val) {
            ++count;
            x += di;
            y += dj;
        }
        return count;
    }

    bool CheckDiagonal1(size_t i, size_t j) const {
        return CountInDirection(i, j, -1, -1) + CountInDirection(i, j, 1, 1) - 1 >= K;
    }

    bool CheckDiagonal2(size_t i, size_t j) const {
        return CountInDirection(i, j, -1, 1) + CountInDirection(i, j, 1, -1) - 1 >= K;
    }
};

std::ostream& operator<<(std::ostream& out, const TicTacToe& field) {
    for (size_t i = 0; i < field.N; ++i) {
        for (size_t j = 0; j < field.N; ++j) {
            switch (field(i, j)) {
                case 0:
                    out << '.';
                    break;
                case 1:
                    out << 'X';
                    break;
                case 2:
                    out << 'O';
                    break;
            }
        }
        out << std::endl;
    }
    return out;
}
```

### F. Работа склада

```cpp
#include <set>
#include <vector>

class Stock {
   private:
    std::vector<std::pair<int, int>> boxes;

    struct ByWComp {
        bool operator()(const std::pair<int, size_t>& a, const std::pair<int, size_t>& b) const {
            if (a.first != b.first)
                return a.first < b.first;
            return a.second > b.second;
        }
    };

    struct ByVComp {
        bool operator()(const std::pair<int, size_t>& a, const std::pair<int, size_t>& b) const {
            if (a.first != b.first)
                return a.first < b.first;
            return a.second > b.second;
        }
    };

    std::set<std::pair<int, size_t>, ByWComp> byW;
    std::set<std::pair<int, size_t>, ByVComp> byV;

   public:
    void Add(int w, int v) {
        size_t id = boxes.size();
        boxes.push_back({w, v});
        byW.insert({w, id});
        byV.insert({v, id});
    }

    int GetByW(int min_w) {
        auto iter = byW.lower_bound({min_w, boxes.size()});

        if (iter == byW.end())
            return -1;

        size_t id = iter->second;

        byW.erase(iter);
        byV.erase({boxes[id].second, id});
        return id;
    }

    int GetByV(int min_v) {
        auto iter = byV.lower_bound({min_v, boxes.size()});

        if (iter == byV.end())
            return -1;

        size_t id = iter->second;

        byV.erase(iter);
        byW.erase({boxes[id].first, id});
        return id;
    }
};
```