#ifndef SERVICE_H
#define SERVICE_H

#include <string>
#include "BankAccount.h"
#include "Currency.h"

std::string toUpperCase(const std::string& input);
std::string trim(const std::string& input);
bool isValidAmount(const std::string& input, double& output);
void displayBankExchange(const BankAccount& account, double amount, const Currency& from, const Currency& to);

#endif // SERVICE_H
