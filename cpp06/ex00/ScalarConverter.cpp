#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::ScalarConverter(const ScalarConverter &source)
{
    *this = source;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs)
{
    if(this != &rhs)
        return *this;
    return *this;
}

ScalarConverter::~ScalarConverter()
{

}


bool ScalarConverter::pseudoliteral(const std::string &str)
{
    if (str == "nan" || str == "nanf" || str == "-inf"|| str == "+inf" || str == "-inff" || str == "+inff")
            return 1;
    return 0; 
}

void ScalarConverter::convertToFloat(const std::string &str)
{ 
    if(str.size() == 1 && !isdigit(str[0]))
    {
        std::cout << "FLOAT: "<<  std::fixed << std::setprecision(1) << static_cast<float>(str[0])<<  "f" << std::endl;
        return;
    }

    long double toFloat = std::strtold(str.c_str(), NULL);
    if(toFloat <  -static_cast<float>(std::numeric_limits<float>::max()) || toFloat > static_cast<float>(std::numeric_limits<float>::max()))
    {
        std::cout<< "FLOAT: It is higher or lower than float max or min"<<std::endl;
    }
    else
    {
        std::cout << "FLOAT: "<< std::fixed << std::setprecision(1)<< toFloat << "f" << std::endl;
    }

}

void ScalarConverter::convertToDouble(const std::string &str)
{
    if(str.size() == 1 && !isdigit(str[0]))
    {
        std::cout << "DOUBLE: " <<  std::fixed << std::setprecision(1) << static_cast<double>(str[0]) << std::endl;
        return;
    }

    long double toDouble = std::strtold(str.c_str(), NULL);

    if(toDouble <  -static_cast<double>(std::numeric_limits<double>::max()) || toDouble > static_cast<double>(std::numeric_limits<double>::max()))
    {
        std::cout<< "DOUBLE: It is higher or lower than double max or min"<<std::endl;
    }
    else
    {
        std::cout << "DOUBLE: "<< std::fixed << std::setprecision(1)<< toDouble << std::endl;
    }

}

void ScalarConverter::convertToChar (const std::string &str)
{
    char toChar = static_cast<char>(str[0]);
    
    if(pseudoliteral(str))
    {
            std::cout << "CHAR: impossivel convert, your input is a pseudo literal"<<std::endl;
            return ;
    }

    if(str.size() != 1 || toChar < std::numeric_limits<char>::min() || toChar > std::numeric_limits<char>::max())
    {
        std::cout << "CHAR: impossivel"<< std::endl;
        return;
    }
    else if (!std::isprint(toChar))
    {
        std::cout << "CHAR: non displayable character"<< std::endl;
    }
    else
    {
        std::cout << "CHAR: '" << toChar << "'" << std::endl;
    }
  
}

void ScalarConverter::convertToInt (const std::string &str)
{
        long double toInt = std::strtold(str.c_str(), NULL);
        if(str.size() == 1 && !isdigit(str[0]))
        {
            std::cout << "INT: " << static_cast<int>(str[0]) << std::endl;
            return;
        }

        if(pseudoliteral(str))
        {
            std::cout<<"INT: impossivel convert, your input is a pseudo literal"<<std::endl;
            return ;
        }
        if(toInt >std::numeric_limits<int>::max() || toInt < std::numeric_limits<int>::min())
        {
            std::cout<<"INT: It is higher or lower than int max or min."<<std::endl;
        }
        else
        {
            std::cout<<"INT: "<<static_cast<int> (toInt)<<std::endl;
        }
}


void ScalarConverter::convert(const std::string &str) 
{
        convertToChar(str);
        convertToInt(str);
        convertToFloat(str);
        convertToDouble(str);
}