#include "Service.h"
#include <algorithm>
#include <sstream>
#include <cctype>
#include <iostream>

// Funkcja usuwająca białe znaki z przodu i z tyłu łańcucha znaków
std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\n\r");
    if (std::string::npos == first) {
        return str;
    }
    size_t last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, (last - first + 1));
}

std::string toUpperCase(const std::string& input) {
    std::string output = input;
    std::transform(output.begin(), output.end(), output.begin(), ::toupper);
    return output;
}

bool isValidAmount(const std::string& input, double& output) {
    std::string cleanInput;
    bool hasDecimal = false;

    for (char c : input) {
        if (c == ',' || c == '.') {
            if (hasDecimal) return false;
            hasDecimal = true;
            cleanInput += '.';
        }
        else if (std::isdigit(c)) {
            cleanInput += c;
        }
        else {
            return false;
        }
    }

    if (cleanInput.empty()) return false;

    std::istringstream stream(cleanInput);
    stream >> output;
    return !stream.fail() && stream.eof();
}

void displayBankExchange(const BankAccount& account, double amount, const Currency& from, const Currency& to) {
    double initialConversion = account.convert(amount, from, to);
    double afterFee = account.applyBankFee(initialConversion);
    double backConversion = account.convert(afterFee, to, from);
    double finalAmount = account.applyBankFee(backConversion);

    std::cout << "Bezposrednia konwersja: " << amount << " " << from.code << " to rownowaznosc " << initialConversion << " " << to.code << "." << std::endl;
    std::cout << "Po naliczeniu 2% prowizji bankowej: " << amount << " " << from.code << " daje " << afterFee << " " << to.code << "." << std::endl;
    std::cout << "Konwersja z powrotem po 2% prowizji: " << afterFee << " " << to.code << " daje " << finalAmount << " " << from.code << "." << std::endl;
}


