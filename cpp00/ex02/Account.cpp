#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount= 0;
int Account::_totalNbDeposits= 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp()
{
    std::time_t time = std::time(NULL);

    std::cout << std::setfill('0') <<"[" << 1900 + std::localtime(&time)->tm_year
            << std::setw(2) << 1 + std::localtime(&time)->tm_mon
            <<  std::setw(2) << std::localtime(&time)->tm_mday <<  "_"
            <<  std::setw(2) << std::localtime(&time)->tm_hour
            <<  std::setw(2) << std::localtime(&time)->tm_min
            <<  std::setw(2) << std::localtime(&time)->tm_sec 
            << "] ";
}

Account::Account(int initial_deposit) 
{
    _accountIndex = Account::_nbAccounts++;
    _amount = initial_deposit;
    _totalAmount += _amount;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << initial_deposit << ";";
    std::cout << "created" << std::endl;
}

int Account::getNbAccounts( void ) 
{
    return _nbAccounts;
}

int Account::getTotalAmount( void ) 
{
    return _totalAmount;
}

int Account::getNbDeposits(void) 
{
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void) 
{
    return _totalNbWithdrawals;
}

int     Account::checkAmount(void) const 
{
    return _amount;
}

void    Account::displayAccountsInfos(void) 
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";";
    std::cout << "total:" << getTotalAmount() << ";";
    std::cout << "deposits:" << getNbDeposits() << ";";
    std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void    Account::makeDeposit(int deposit) 
{
    _displayTimestamp();
    _nbDeposits++;
    _totalNbDeposits++;
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << _amount << ";";
    std::cout << "deposit:" << deposit << ";";
    _totalAmount += deposit;
    _amount += deposit;
    std::cout << "amount:" << _amount << ";";
    std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}

bool    Account::makeWithdrawal(int withdrawal) 
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << _amount << ";";
    std::cout << "withdrawal:";
    if (withdrawal > checkAmount()) {
        std::cout << "refused\n";
        return false;
    }
    std::cout << withdrawal << ";";
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    _totalAmount -= withdrawal;
    _amount -= withdrawal;
    std::cout << "amount:" << _amount << ";";
    std::cout << "nb_withdrawals:" << _nbDeposits << std::endl;
    return true;
}


void    Account::displayStatus(void) const 
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "deposits:" << _nbDeposits << ";";
    std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

Account::~Account(void)
{
    _nbAccounts--;
    this->_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "closed" << std::endl;
}
