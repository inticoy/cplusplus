/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:08:24 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/08 17:00:51 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

#include <ctime>
#include <iostream>
#include <string>

namespace color {
std::string yellow = "\033[1;33m";
std::string end = "\033[1;0m";
}  // namespace color

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp() {
  time_t t = time(0);       // get time now
  tm *now = localtime(&t);  // convert time_t t into tm structure
  std::string year = std::to_string(now->tm_year + 1900);
  std::string month = (now->tm_mon >= 10) ? std::to_string(now->tm_mon)
                                          : "0" + std::to_string(now->tm_mon);
  std::string day = (now->tm_mday >= 10) ? std::to_string(now->tm_mday)
                                         : "0" + std::to_string(now->tm_mday);
  std::string hour = (now->tm_hour >= 10) ? std::to_string(now->tm_hour)
                                          : "0" + std::to_string(now->tm_hour);
  std::string min = (now->tm_min >= 10) ? std::to_string(now->tm_min)
                                        : "0" + std::to_string(now->tm_min);
  std::string sec = (now->tm_sec >= 10) ? std::to_string(now->tm_sec)
                                        : "0" + std ::to_string(now->tm_sec);
  std::string timestamp = year + month + day + "_" + hour + min + sec;
  std::cout << color::yellow << "[" << timestamp << "]" << color::end << " ";
}
Account::Account() {}

Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts++),
      _amount(initial_deposit),
      _nbDeposits(0),
      _nbWithdrawals(0) {
  _displayTimestamp();
  _totalAmount += initial_deposit;
  std::cout << "index:" << _accountIndex << ";";
  std::cout << "amount:" << _amount << ";";
  std::cout << "created" << std::endl;
}
Account::~Account() {
  _displayTimestamp();
  _nbAccounts--;
  _totalAmount -= _amount;
  _totalNbDeposits -= _nbDeposits;
  _totalNbWithdrawals -= _nbWithdrawals;
  std::cout << "index:" << _accountIndex << ";";
  std::cout << "amount:" << _amount << ";";
  std::cout << "closed" << std::endl;
}
void Account::makeDeposit(int deposit) {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";";
  std::cout << "p_amount:" << _amount << ";";
  std::cout << "deposit:" << deposit << ";";
  _amount += deposit;
  _totalAmount += deposit;
  _nbDeposits++;
  _totalNbDeposits++;
  std::cout << "amount:" << _amount << ";";
  std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}
bool Account::makeWithdrawal(int withdrawal) {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";";
  std::cout << "p_amount:" << _amount << ";";
  if (_amount < withdrawal) {
    std::cout << "withdrawal:refused" << std::endl;
    return false;
  }
  _amount -= withdrawal;
  _totalAmount -= withdrawal;
  _nbWithdrawals++;
  _totalNbWithdrawals++;
  std::cout << "withdrawal:" << withdrawal << ";";
  std::cout << "amount:" << _amount << ";";
  std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
  return true;
}
int Account::checkAmount() const { return _amount; }
void Account::displayStatus() const {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";";
  std::cout << "amount:" << _amount << ";";
  std::cout << "deposits:" << _nbDeposits << ";";
  std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

int Account::getNbAccounts() { return _nbAccounts; }
int Account::getTotalAmount() { return _totalAmount; }
int Account::getNbDeposits() { return _totalNbDeposits; }
int Account::getNbWithdrawals() { return _totalNbWithdrawals; }
void Account::displayAccountsInfos() {
  _displayTimestamp();
  std::cout << "accounts:" << _nbAccounts << ";";
  std::cout << "total:" << _totalAmount << ";";
  std::cout << "deposits:" << _totalNbDeposits << ";";
  std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}