#include "BankAccount.h"

double BankAccount::convert(double amount, const Currency& from, const Currency& to) const {
    return amount * from.fromUSD * to.toUSD;
}

double BankAccount::applyBankFee(double amount) const {
    return amount * 0.98;
}

BankAccount::~BankAccount() {}

