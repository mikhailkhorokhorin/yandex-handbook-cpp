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