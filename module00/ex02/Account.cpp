/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:08:24 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/06 14:13:31 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

#define C_RED "\033[1;31m"
#define C_YEL "\033[1;33m"
#define C_BLU "\033[1;34m"
#define C_END "\033[1;0m"

using std::cout;
using std::endl;

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void) {}
Account::Account(void) {}

Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts++), _amount(initial_deposit), _nbDeposits(0),
      _nbWithdrawals(0)
{
    _totalAmount += initial_deposit;
}
Account::~Account(void)
{
    _nbAccounts--;
    _totalAmount -= _amount;
    _totalNbDeposits -= _nbDeposits;
    _totalNbWithdrawals -= _nbWithdrawals;
}
void Account::makeDeposit(int deposit)
{
    _amount += deposit;
    _totalAmount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
}
bool Account::makeWithdrawal(int withdrawal)
{
    if (_amount < withdrawal)
    {
        cout << C_RED "[Withdrawal Failed]" C_END;
        cout << " Not enough amount." << endl;
        return (false);
    }
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    return (true);
}
int Account::checkAmount(void) const { return (_amount); }
void Account::displayStatus(void) const
{
    cout << C_YEL "[Account Status]" C_END;
    cout << " accountIndex : " << _accountIndex;
    cout << " amount : " << _amount;
    cout << " nbDeposits : " << _nbDeposits;
    cout << " nbWithdrawals : " << _nbWithdrawals << endl;
}

int Account::getNbAccounts(void) { return (_nbAccounts); }
int Account::getTotalAmount(void) { return (_totalAmount); }
int Account::getNbDeposits(void) { return (_totalNbDeposits); }
int Account::getNbWithdrawals(void) { return (_totalNbWithdrawals); }
void Account::displayAccountsInfos(void)
{
    cout << C_BLU "[Accounts Infos]" C_END;
    cout << " nbAccounts : " << _nbAccounts;
    cout << " totalAmount : " << _totalAmount;
    cout << " totalNbDeposits : " << _totalNbDeposits;
    cout << " totalNbWithdrawals : " << _totalNbWithdrawals << endl;
}