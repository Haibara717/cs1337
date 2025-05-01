
#include "Date.h"


#include <iostream>
#include <string>


using namespace std;

// Set the values of the Date object
void Date::set(int month_, int day_, int year_, int hour_) {
    month = month_;
    day = day_;
    year = year_;
    hour = hour_;
}

int Date::getMonth() const {
    return month;
}

int Date::getDay() const {
    return day;
}

int Date::getYear() const {
    return year;
}

int Date::getHour() const {
    return hour;
}

void Date::print() const {
    string monthNames[] = {
        "", "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    cout << monthNames[month] << " " << day << ", " << year << ", ";

    
    
    cout << hour << ":00";
}
