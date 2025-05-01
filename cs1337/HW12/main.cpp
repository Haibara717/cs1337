#include <iostream>
#include <string>
#include "Date.h"
using namespace std;

// Extracts the month (mm) from a string formatted as "mm/dd/yyyy/hh"
int getMonth(string d) {
    return stoi(d.substr(0, 2));
}

// Extracts the day (dd) from a string formatted as "mm/dd/yyyy/hh"
int getDay(string d) {
    return stoi(d.substr(3, 2));
}

// Extracts the year (yyyy) from a string formatted as "mm/dd/yyyy/hh"
int getYear(string d) {
    return stoi(d.substr(6, 4));
}

// Extracts the hour (hh) from a string formatted as "mm/dd/yyyy/hh"
int getHour(string d) {
    return stoi(d.substr(11, 2));
}

int main() {
    int month, day, year, hour;

    // Test data for subtraction (-) and relational (==, <, <=) operators
    const int NUM_DATES_SUBTRACT = 4, NUM_DATES_RELATIONAL = 5;
    string dateArraySubtract[NUM_DATES_SUBTRACT] = {
        "01/01/2097/20", "02/12/2098/00", "02/13/2100/13","12/31/2103/23"
    };
    string dateArrayRelational[NUM_DATES_RELATIONAL] = {
        "01/01/2097/20", "01/01/2097/21", "01/02/2097/20",
        "02/01/2097/20", "01/01/2098/20"
    };

    // Display title for relational operator tests
    string title = "Overloaded relational operators";
    string underline;
    underline.assign(title.length(), '-');
    cout << title << endl << underline << endl;

    Date d1, d2;

    // Loop through all combinations of relational test dates
    for (int i = 0; i < NUM_DATES_RELATIONAL; i++)
        for (int j = 0; j < NUM_DATES_RELATIONAL; j++) {
            // Extract and set d1 from the i-th date string
            month = getMonth(dateArrayRelational[i]);
            day = getDay(dateArrayRelational[i]);
            year = getYear(dateArrayRelational[i]);
            hour = getHour(dateArrayRelational[i]);
            d1.set(month, day, year, hour);

            // Print d1
            cout << endl << "============================================\n";
            cout << "d1: ";
            d1.print();

            // Extract and set d2 from the j-th date string
            month = getMonth(dateArrayRelational[j]);
            day = getDay(dateArrayRelational[j]);
            year = getYear(dateArrayRelational[j]);
            hour = getHour(dateArrayRelational[j]);
            d2.set(month, day, year, hour);

            // Print d2
            cout << ", d2: ";
            d2.print();
            cout << endl;

            // Apply and display results of relational operators
            if (d1 < d2) cout << "(d1 < d2) ";
            if (d2 < d1) cout << "(d2 < d1) ";
            if (d1 == d2) cout << "(d2 == d1) ";
            if (d1 <= d2) cout << "(d1 <= d2) ";
            if (d2 <= d1) cout << "(d2 <= d1) ";
        }

    // Display title for subtraction (-) operator test
    title = "Overloaded - operator";
    underline.assign(title.length(), '-');
    cout << endl << endl << title << endl << underline << endl;

    // Loop through all combinations of subtraction test dates
    for (int i = 0; i < NUM_DATES_SUBTRACT; i++)
        for (int j = 0; j < NUM_DATES_SUBTRACT; j++) {
            // Set d1
            month = getMonth(dateArraySubtract[i]);
            day = getDay(dateArraySubtract[i]);
            year = getYear(dateArraySubtract[i]);
            hour = getHour(dateArraySubtract[i]);
            d1.set(month, day, year, hour);

            // Print d1
            cout << endl << "============================================\n";
            cout << "d1: ";
            d1.print();

            // Set d2
            month = getMonth(dateArraySubtract[j]);
            day = getDay(dateArraySubtract[j]);
            year = getYear(dateArraySubtract[j]);
            hour = getHour(dateArraySubtract[j]);
            d2.set(month, day, year, hour);

            // Print d2
            cout << ", d2: ";
            d2.print();
            cout << endl;

            // Subtract d1 from d2 and print the result
            cout << "d2 - d1 = " << (d2 - d1) << " hours" << endl;
        }

    return 0;
}
