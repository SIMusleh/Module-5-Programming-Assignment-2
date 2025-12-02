/* Program name: dateExcept.h
 * Author: Sahar Musleh
 * Date last updated: 12/01/2025
 * Purpose: Defines custom exception classes for invalid date components.
 */

#ifndef DATEEXCEPT_H
#define DATEEXCEPT_H

#include <stdexcept>  // For std::invalid_argument base class
#include <string>     // For passing error messages as strings

// Exception class for invalid month values
class invalid_month : public std::invalid_argument {
public:
    // Constructor passes error message to std::invalid_argument
    explicit invalid_month(const std::string& msg) : std::invalid_argument(msg) {}
};

// Exception class for invalid day values
class invalid_day : public std::invalid_argument {
public:
    // Constructor passes error message to std::invalid_argument
    explicit invalid_day(const std::string& msg) : std::invalid_argument(msg) {}
};

// Exception class for invalid year values
class invalid_year : public std::invalid_argument {
public:
    // Constructor passes error message to std::invalid_argument
    explicit invalid_year(const std::string& msg) : std::invalid_argument(msg) {}
};

#endif
