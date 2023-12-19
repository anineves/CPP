#ifndef SCALACONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <iomanip> 
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <limits>
#include <float.h>
#include <climits>
#include <math.h>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &source);
        ScalarConverter &operator = (const ScalarConverter &rhs);

    public:
        ~ScalarConverter();
        static void convert(const std::string &str);
        static void convertToChar(const std::string &str);
        static void convertToInt(const std::string &str);
        static void convertToFloat(const std::string &str);
        static void convertToDouble(const std::string &str);
        static bool	noDigitChar(const std::string &str);
        static bool pseudoliteral(const std::string &str);
};
#endif