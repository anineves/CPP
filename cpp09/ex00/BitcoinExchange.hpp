#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <sstream> 
#include <limits.h>
#include <stdlib.h>
#include <filesystem>
#include <exception>
#include <float.h>
#include <iomanip>



class BitcoinExchange {
  private:
    std::map<std::string, float>    data;

  public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &source);
    BitcoinExchange& operator=(const BitcoinExchange &rhs);
    ~BitcoinExchange();

    void parseCsv();
    bool is_int(std::string value);
    bool is_float(std::string value);
    bool is_valid_date(std::string date);
    void parseArgv(std::string input);
    void ft_print(const std::string &date, const float nbBtc);
    bool is_valid_value (float nbBtc);

};

#endif
