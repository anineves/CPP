#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() 
{  
    parseCsv();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &source)
    : data(source.data) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs) {
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
		while(getline(file, line))
		{
			std::string date;
			int	pos;
			pos = line.find(',');
			date = line.substr(0, pos);
			std::string value;
            value = line.substr(pos + 1);
            if(is_int(value) || is_float(value))
            {
                this->data.insert(std::pair<std::string, float>(date, pos))   
            }

		}
	}
	file.close();
}

bool BitcoinExchange::is_int(std::string value)
{
   
}

bool BitcoinExchange::is_float(std::string value)
{
    if (value.empty()) {
        return false; 
    }
    size_t start = 0;
    if (value[0] == '+' || value[0] == '-') {
        start = 1; 
    }
    for (size_t i = start; i < value.length(); ++i) {
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