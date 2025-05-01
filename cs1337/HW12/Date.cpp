#include <iostream>
#include "Date.h"
using namespace std;

// Sets the values for the date object
void Date::set(int month_, int day_, int year_, int hour_) {
    month = month_;
    day = day_;
    year = year_;
    hour = hour_;
}

// Prints the date in the format: "Month dd, yyyy, hh:00"
void Date::print() {
    static const string monthNames[12] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    cout << monthNames[month - 1] << " ";
    cout << day << ", ";
    cout << year << ", ";
    cout << hour << ":00";
}

// Overloads the < operator to compare two Date objects chronologically
bool Date::operator<(const Date & rhs) {
    if (year != rhs.year)
        return year < rhs.year;
    if (month != rhs.month)
        return month < rhs.month;
    if (day != rhs.day)
        return day < rhs.day;
    return hour < rhs.hour;
}

// Overloads the == operator to check full equality of year, month, day, and hour
bool Date::operator==(const Date & rhs) {
    return (year == rhs.year &&
            month == rhs.month &&
            day == rhs.day &&
            hour == rhs.hour);
}

// Overloads the <= operator using the definitions of < and ==
bool Date::operator<=(const Date & rhs) {
    return (*this < rhs) || (*this == rhs);
}

// Checks whether a given year is a leap year
bool isLeapYear(int y) {
    return ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0));
}

// Converts a full date into total hours since 01/01/0001 00:00
int toHoursTotal(int y, int m, int d, int h) {
    int days = 0;

    // 1. Add days for all complete years before year y
    for (int i = 1; i < y; i++) {
        days += isLeapYear(i) ? 366 : 365;
    }

    // 2. Add days for all complete months before month m in the current year
    if (isLeapYear(y)) {
        static const int leapDaysBeforeMonth[12] = {0,31,60,91,121,152,182,213,244,274,305,335};
        days += leapDaysBeforeMonth[m - 1];
    } else {
        static const int normDaysBeforeMonth[12] = {0,31,59,90,120,151,181,212,243,273,304,334};
        days += normDaysBeforeMonth[m - 1];
    }

    // 3. Add days passed in the current month (subtract 1 since the day starts from 0)
    days += d - 1;

    // 4. Convert total days into hours and add hour component
    return days * 24 + h;
}

// Overloads the - operator to return the difference in hours between two Date objects
int Date::operator-(const Date & rhs) {
    int hTHIS = toHoursTotal(year, month, day, hour);
    int hRHS = toHoursTotal(rhs.year, rhs.month, rhs.day, rhs.hour);
    return hTHIS - hRHS;
}
