#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <sstream> 
#include <limits.h>


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

};
#endif