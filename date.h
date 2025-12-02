/* Program name: date.h
 * Author: Sahar Musleh
 * Date last updated: 11/30/2025
 * Purpose: Header file for Date class with validation, leap year logic, operator overloading, and exception handling.
 */

#ifndef DATE_H
#define DATE_H

#include <iostream>
#include "dateExcept.h"

class date {
private:
    int month;
    int day;
    int year;

    bool isValidDate(int m, int d, int y) const;
    int daysInMonth(int m, int y) const;

public:
    date(int m = 1, int d = 1, int y = 2000);

    int getMonth() const;
    int getDay() const;
    int getYear() const;

    void setMonth(int m);
    void setDay(int d);
    void setYear(int y);

    bool isLeapYear(int y) const;

    date operator+(int days) const;
    friend date operator+(int days, const date& dt);

    date operator-(int days) const;
    friend date operator-(int days, const date& dt);

    date& operator++();
    date operator++(int);
    date& operator--();
    date operator--(int);

    bool operator==(const date& other) const;
    bool operator!=(const date& other) const;
    bool operator<(const date& other) const;
    bool operator<=(const date& other) const;
    bool operator>(const date& other) const;
    bool operator>=(const date& other) const;

    friend std::ostream& operator<<(std::ostream& out, const date& dt);
    friend std::istream& operator>>(std::istream& in, date& dt);
};

#endif
