/* Program name: dateExcept.h
 * Author: Sahar Musleh
 * Date last updated: 11/30/2025
 * Purpose: Defines custom exception classes for invalid date components.
 */

#ifndef DATEEXCEPT_H
#define DATEEXCEPT_H

#include <stdexcept>
#include <string>

class invalid_month : public std::invalid_argument {
public:
    explicit invalid_month(const std::string& msg) : std::invalid_argument(msg) {}
};

class invalid_day : public std::invalid_argument {
public:
    explicit invalid_day(const std::string& msg) : std::invalid_argument(msg) {}
};

class invalid_year : public std::invalid_argument {
public:
    explicit invalid_year(const std::string& msg) : std::invalid_argument(msg) {}
};

#endif
