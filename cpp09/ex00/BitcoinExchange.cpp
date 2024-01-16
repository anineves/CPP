#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    parseCsv();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &source)
    : data(source.data) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
    if (this != &rhs)
        this->data = rhs.data;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::parseCsv()
{
    std::ifstream file("data.csv");
    if (!file.good())
        throw std::string("data.csv file could't open or don't exist");
    else
    {
        std::string line;
        getline(file, line);
        while (getline(file, line))
        {
            std::string date;
            int pos;
            pos = line.find(',');
            date = line.substr(0, pos);
            std::string value;
            value = line.substr(pos + 1);
            std::cout << "value " << value << std::endl;
            if ((is_valid_date(date) && is_int(value) ) || is_float(value))
            {
                float valueBtc = strtof(value.c_str(), NULL);
                this->data.insert(std::pair<std::string, float>(date, valueBtc));
            }
        }
    }
    file.close();
}

bool BitcoinExchange::is_valid_date(std::string date)
{
    if (date.length() != 10)
    {
        return false;
    }

    for (int i = 0; i < 10; ++i)
    {
        if (i == 4 || i == 7)
        {
            if (date[i] != '-')
            {
                return false;
            }
        }
        else
        {
            if (!isdigit(date[i]))
            {
                return false;
            }
        }
    }

    int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());

    if (year < 2009 || year > 2022 || month < 1 || month > 12 || day < 1 || day > 31)
    {
        return false;
    }
    if ((month == 4 || month == 6 || month == 7 || month == 9 || month == 11) && day > 30)
        return false;
    if (month == 2)
    {
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
        {
            if (day > 29)
                return false;
        }
        else
        {
            if (day > 28)
                return false;
        }
    }
    return true;
}

bool BitcoinExchange::is_int(std::string value)
{
    if (value.empty())
    {
        return false;
    }
    size_t start = 0;
    if (value[0] == '+' || value[0] == '-')
    {
        start = 1;
    }
    for (size_t i = start; i < value.length(); ++i)
    {
        if (!std::isdigit(value[i]))
            return false;
    }

    long value_long = strtol(value.c_str(), NULL, 10);
    if (value_long > INT_MAX || value_long < INT_MIN)
    {
        return false;
    }

    return true;
}

bool BitcoinExchange::is_float(std::string value)
{
    if (value.empty())
    {
        return false;
    }

    size_t start = 0;
    if (value[0] == '+' || value[0] == '-')
    {
        start = 1;
    }

    int dec = 0;

    for (size_t i = start; i < value.length(); i++)
    {
        if (value[i] == '.')
        {
            if (dec == 0)
                dec = 1;
            else
                return false;
        }
        else if (value[i] == 'f')
        {
            if (i == value.length() - 1)
                continue;
            else
                return false;
        }
        else if (!std::isdigit(value[i]))
            return false;
    }

    long value_long = strtol(value.c_str(), NULL, 10);
    if (value_long > FLT_MAX || value_long < FLT_MIN)
    {
        return false;
    }

    return true;
}

void BitcoinExchange::ft_print(const std::string &date, const float nbBtc) 
{
    std::map<std::string, float>::iterator it = this->data.lower_bound(date);

    if (it != this->data.begin() && it->first != date)
        it--;

    float value;
    value = nbBtc * it->second ;
    
    std::cout << it->first << " => " << nbBtc << " = "  << value << std::fixed << std::setprecision(1)<< std::endl;
}

bool BitcoinExchange::is_valid_value(float nbBtc)
{   
    	if (nbBtc < 0)
        {
            std::cerr << "Error: not a positive number." << std::endl;
            return false;
        }   
        if ( nbBtc > 1000)
        {
            std::cerr << "Error: too large a number"<< std::endl;
            return false;
        }
        return true;

}


void BitcoinExchange::parseArgv(const std::string input)
{
    std::string line;
    std::ifstream file(input.c_str());
    if (!file.good())
        throw std::string("data.csv file could't open or don't exist");

    if (file.peek() == std::ifstream::traits_type::eof())
        throw std::string("This file is empty");

    getline(file, line);
    if (line != "date | value")
        throw("Invalid file format");
    while (getline(file, line))
    {
        std::string date;
        int pos;
        pos = line.find('|');
        date = line.substr(0, pos - 1);
        std::string value;
        value = line.substr(pos + 2);

        if (!is_valid_date(date)) 
        {
            std::cerr << "Error: bad input => " << line << std::endl;
                continue;
        }
        float nbBtc;
        nbBtc = strtof(value.c_str(), NULL);
        if(!is_valid_value(nbBtc))
            continue;
        std::cout << "nbBtc " <<nbBtc << std::endl;
        ft_print(date, nbBtc);
    }


        file.close();
    }
