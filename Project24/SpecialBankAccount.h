#ifndef SPECIALBANKACCOUNT_H
#define SPECIALBANKACCOUNT_H

#include "BankAccount.h"

class SpecialBankAccount : public BankAccount {
public:
    double convert(double amount, const Currency& from, const Currency& to) const override;
};

#endif // SPECIALBANKACCOUNT_H
