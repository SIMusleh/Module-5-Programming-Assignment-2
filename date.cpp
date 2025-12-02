/* Program name: date.cpp
 * Author: Sahar Musleh
 * Date last updated: 12/01/2025
 * Purpose: Implements Date class with operator overloading and custom exception handling.
 */

#include "date.h"
#include <iomanip>   // For formatting output (setw, setfill)
#include <iostream>  // For input/output streams

// Returns number of days in a given month/year
int date::daysInMonth(int m, int y) const {
    if (m == 2) return isLeapYear(y) ? 29 : 28; // February: check leap year
    if (m == 4 || m == 6 || m == 9 || m == 11) return 30; // April, June, Sept, Nov
    return 31; // All other months
}

// Validates if the given date components form a valid date
bool date::isValidDate(int m, int d, int y) const {
    if (y < 0 || m < 1 || m > 12) return false; // Year must be positive, month 1-12
    if (d < 1 || d > daysInMonth(m, y)) return false; // Day must fit month/year
    return true;
}

// Constructor: initializes date or throws exceptions if invalid
date::date(int m, int d, int y) {
    if (m < 1 || m > 12) throw invalid_month("Month must be between 1 and 12.");
    if (y < 0) throw invalid_year("Year must be positive.");
    if (d < 1 || d > daysInMonth(m, y)) throw invalid_day("Day is out of range for given month/year.");
    month = m; day = d; year = y;
}

// Getters
int date::getMonth() const { return month; }
int date::getDay() const { return day; }
int date::getYear() const { return year; }

// Setter for month with validation
void date::setMonth(int m) {
    if (m < 1 || m > 12) throw invalid_month("Month must be between 1 and 12.");
    if (!isValidDate(m, day, year)) throw invalid_day("Day is invalid for new month.");
    month = m;
}

// Setter for day with validation
void date::setDay(int d) {
    if (d < 1 || d > daysInMonth(month, year)) throw invalid_day("Day is out of range for current month/year.");
    day = d;
}

// Setter for year with validation
void date::setYear(int y) {
    if (y < 0) throw invalid_year("Year must be positive.");
    if (!isValidDate(month, day, y)) throw invalid_day("Day is invalid for new year.");
    year = y;
}

// Checks if a given year is a leap year
bool date::isLeapYear(int y) const {
    if (y % 4 != 0) return false;
    if (y % 100 != 0) return true;
    return (y % 400 == 0);
}

// Adds a number of days to the current date
date date::operator+(int days) const {
    date temp = *this; // Copy current date
    temp.day += days;
    // Adjust month/year if day exceeds current month
    while (temp.day > temp.daysInMonth(temp.month, temp.year)) {
        temp.day -= temp.daysInMonth(temp.month, temp.year);
        temp.month++;
        if (temp.month > 12) { temp.month = 1; temp.year++; }
    }
    return temp;
}

// Friend function for int + date
date operator+(int days, const date& dt) { return dt + days; }

// Subtracts a number of days from the current date
date date::operator-(int days) const {
    date temp = *this; // Copy current date
    temp.day -= days;
    // Adjust month/year if day goes below 1
    while (temp.day < 1) {
        temp.month--;
        if (temp.month < 1) { temp.month = 12; temp.year--; }
        temp.day += temp.daysInMonth(temp.month, temp.year);
    }
    return temp;
}

// Friend function for int - date
date operator-(int days, const date& dt) { return dt - days; }

// Pre-increment: move to next day
date& date::operator++() { *this = *this + 1; return *this; }

// Post-increment: move to next day, return old value
date date::operator++(int) { date old = *this; ++(*this); return old; }

// Pre-decrement: move to previous day
date& date::operator--() { *this = *this - 1; return *this; }

// Post-decrement: move to previous day, return old value
date date::operator--(int) { date old = *this; --(*this); return old; }

// Comparison operators for equality and ordering
bool date::operator==(const date& other) const { return year == other.year && month == other.month && day == other.day; }
bool date::operator!=(const date& other) const { return !(*this == other); }
bool date::operator<(const date& other) const {
    if (year != other.year) return year < other.year;
    if (month != other.month) return month < other.month;
    return day < other.day;
}
bool date::operator<=(const date& other) const { return *this < other || *this == other; }
bool date::operator>(const date& other) const { return !(*this <= other); }
bool date::operator>=(const date& other) const { return !(*this < other); }

// Output operator: prints date in YYYY-MM-DD format
std::ostream& operator<<(std::ostream& out, const date& dt) {
    out << dt.year << "-"
        << std::setw(2) << std::setfill('0') << dt.month << "-"
        << std::setw(2) << std::setfill('0') << dt.day;
    return out;
}

// Input operator: reads date values and validates them
std::istream& operator>>(std::istream& in, date& dt) {
    int m, d, y;
    in >> m >> d >> y;
    if (m < 1 || m > 12) throw invalid_month("Invalid month entered.");
    if (y < 0) throw invalid_year("Invalid year entered.");
    if (d < 1 || d > dt.daysInMonth(m, y)) throw invalid_day("Invalid day entered.");
    dt.month = m; dt.day = d; dt.year = y;
    return in;
}
