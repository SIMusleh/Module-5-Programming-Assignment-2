/* Program name: date.h
 * Author: Sahar Musleh
 * Date last updated: 12/01/2025
 * Purpose: Header file for Date class with validation, leap year logic, operator overloading, and exception handling.
 */

#ifndef DATE_H
#define DATE_H

#include <iostream>       // For input/output stream operations
#include "dateExcept.h"   // Custom exception classes for invalid date components

class date {
private:
    int month;  // Stores month value (1-12)
    int day;    // Stores day value (depends on month and leap year)
    int year;   // Stores year value (must be positive)

    // Helper function to validate a full date (month, day, year)
    bool isValidDate(int m, int d, int y) const;

    // Helper function to return number of days in a given month/year
    int daysInMonth(int m, int y) const;

public:
    // Constructor with default values; throws exceptions if invalid
    date(int m = 1, int d = 1, int y = 2000);

    // Getters
    int getMonth() const; // Returns month
    int getDay() const;   // Returns day
    int getYear() const;  // Returns year

    // Setters
    void setMonth(int m); // Sets month (1-12)
    void setDay(int d);   // Sets day (valid for current month/year)
    void setYear(int y);  // Sets year (must be positive)

    // Checks if a given year is a leap year
    bool isLeapYear(int y) const;

    // Arithmetic operators for adding/subtracting days
    date operator+(int days) const;                     // Add days to current date
    friend date operator+(int days, const date& dt);    // Add days (int + date)

    date operator-(int days) const;                     // Subtract days from current date
    friend date operator-(int days, const date& dt);    // Subtract days (int - date)

    // Increment and decrement operators for day navigation
    date& operator++();    // Pre-increment (next day)
    date operator++(int);  // Post-increment (next day)
    date& operator--();    // Pre-decrement (previous day)
    date operator--(int);  // Post-decrement (previous day)

    // Comparison operators for date comparison
    bool operator==(const date& other) const; // Equality check
    bool operator!=(const date& other) const; // Inequality check
    bool operator<(const date& other) const;  // Less than check
    bool operator<=(const date& other) const; // Less than or equal check
    bool operator>(const date& other) const;  // Greater than check
    bool operator>=(const date& other) const; // Greater than or equal check

    // Stream operators for input/output
    friend std::ostream& operator<<(std::ostream& out, const date& dt); // Output date in YYYY-MM-DD format
    friend std::istream& operator>>(std::istream& in, date& dt);        // Input date values (month day year)
};

#endif
