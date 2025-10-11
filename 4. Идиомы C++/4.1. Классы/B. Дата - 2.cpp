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