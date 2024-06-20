#include "SpecialBankAccount.h"

double SpecialBankAccount::convert(double amount, const Currency& from, const Currency& to) const {
    double baseConversion = BankAccount::convert(amount, from, to);
    return baseConversion * 0.95; // Dodatkowa znizka
}