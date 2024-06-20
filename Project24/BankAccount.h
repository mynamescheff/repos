#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include "Currency.h"

class BankAccount {
public:
    virtual double convert(double amount, const Currency& from, const Currency& to) const;
    virtual double applyBankFee(double amount) const;
    virtual ~BankAccount();
};

#endif // BANKACCOUNT_H
