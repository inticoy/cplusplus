/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:08:24 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/07 15:59:14 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <string>

#define C_YEL "\033[1;33m"
#define C_END "\033[1;0m"

using std::cout;
using std::endl;
using std::localtime;
using std::string;
using std::time;
using std::to_string;

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp()
{
    time_t t = time(0);      // get time now
    tm *now = localtime(&t); // convert time_t t into tm structure
    string year = to_string(now->tm_year + 1900);
    string month = ((now->tm_mon >= 10) ? to_string(now->tm_mon)
                                        : "0" + to_string(now->tm_mon));
    string day = ((now->tm_mday >= 10) ? to_string(now->tm_mday)
                                       : "0" + to_string(now->tm_mday));
    string hour = ((now->tm_hour >= 10) ? to_string(now->tm_hour)
                                        : "0" + to_string(now->tm_hour));
    string min = ((now->tm_min >= 10) ? to_string(now->tm_min)
                                      : "0" + to_string(now->tm_min));
    string sec = ((now->tm_sec >= 10) ? to_string(now->tm_sec)
                                      : "0" + to_string(now->tm_sec));
    string timestamp = year + month + day + "_" + hour + min + sec;
    cout << C_YEL "[" << timestamp << "]" C_END << " ";
}
Account::Account() {}

Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts++), _amount(initial_deposit), _nbDeposits(0),
      _nbWithdrawals(0)
{
    _displayTimestamp();
    _totalAmount += initial_deposit;
    cout << "index:" << _accountIndex << ";";
    cout << "amount:" << _amount << ";";
    cout << "created" << endl;
}
Account::~Account()
{
    _displayTimestamp();
    _nbAccounts--;
    _totalAmount -= _amount;
    _totalNbDeposits -= _nbDeposits;
    _totalNbWithdrawals -= _nbWithdrawals;
    cout << "index:" << _accountIndex << ";";
    cout << "amount:" << _amount << ";";
    cout << "closed" << endl;
}
void Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    cout << "index:" << _accountIndex << ";";
    cout << "p_amount:" << _amount << ";";
    cout << "deposit:" << deposit << ";";
    _amount += deposit;
    _totalAmount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
    cout << "amount:" << _amount << ";";
    cout << "nb_deposits:" << _nbDeposits << endl;
}
bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    cout << "index:" << _accountIndex << ";";
    cout << "p_amount:" << _amount << ";";
    if (_amount < withdrawal)
    {
        cout << "withdrawal:refused" << endl;
        return false;
    }
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    cout << "withdrawal:" << withdrawal << ";";
    cout << "amount:" << _amount << ";";
    cout << "nb_withdrawals:" << _nbWithdrawals << endl;
    return true;
}
int Account::checkAmount() const { return _amount; }
void Account::displayStatus() const
{
    _displayTimestamp();
    cout << "index:" << _accountIndex << ";";
    cout << "amount:" << _amount << ";";
    cout << "deposits:" << _nbDeposits << ";";
    cout << "withdrawals:" << _nbWithdrawals << endl;
}

int Account::getNbAccounts() { return _nbAccounts; }
int Account::getTotalAmount() { return _totalAmount; }
int Account::getNbDeposits() { return _totalNbDeposits; }
int Account::getNbWithdrawals() { return _totalNbWithdrawals; }
void Account::displayAccountsInfos()
{
    _displayTimestamp();
    cout << "accounts:" << _nbAccounts << ";";
    cout << "total:" << _totalAmount << ";";
    cout << "deposits:" << _totalNbDeposits << ";";
    cout << "withdrawals:" << _totalNbWithdrawals << endl;
}