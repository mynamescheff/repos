#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <limits>

// Function to convert string to upper case
std::string toUpperCase(const std::string& input) {
    std::string output = input;
    std::transform(output.begin(), output.end(), output.begin(), ::toupper);
    return output;
}

// Function to verify and convert a string to a floating-point number
bool isValidAmount(const std::string& input, double& output) {
    std::string cleanInput;
    bool hasDecimal = false;

    for (char c : input) {
        if (c == ',' || c == '.') {
            if (hasDecimal) return false; // Return false if more than one decimal point or comma
            hasDecimal = true;
            cleanInput += '.'; // Normalize to dot
        }
        else if (std::isdigit(c)) {
            cleanInput += c; // Collect digits
        }
        else {
            return false; // Return false if non-digit and non-decimal character found
        }
    }

    if (cleanInput.empty()) return false; // Ensure the string is not empty

    std::istringstream stream(cleanInput);
    stream >> output;
    return !stream.fail() && stream.eof(); // Return true if conversion succeeded and all input was read
}

class Currency {
public:
    std::string code; // Currency code, e.g., USD
    std::string name; // Full currency name, e.g., United States Dollar
    double toUSD;     // Exchange rate to USD
    double fromUSD;   // Exchange rate from USD

    Currency() : code(""), name(""), toUSD(0.0), fromUSD(0.0) {}
    Currency(std::string c, std::string n, double t, double f) : code(c), name(n), toUSD(t), fromUSD(f) {}
    Currency(const Currency& other) : code(other.code), name(other.name), toUSD(other.toUSD), fromUSD(other.fromUSD) {}
    ~Currency() {}
};

class BankAccount {
public:
    virtual double convert(double amount, const Currency& from, const Currency& to) const {
        return amount * from.fromUSD * to.toUSD;
    }
    virtual double applyBankFee(double amount) const {
        return amount * 0.98;
    }
    virtual ~BankAccount() {}
};

class SpecialAccount : public BankAccount {
public:
    double convert(double amount, const Currency& from, const Currency& to) const override {
        double baseConversion = BankAccount::convert(amount, from, to);
        return baseConversion * 0.95; // Additional discount
    }
};

void displayBankExchange(const BankAccount& account, double amount, const Currency& from, const Currency& to) {
    double initialConversion = account.convert(amount, from, to);
    double afterFee = account.applyBankFee(initialConversion);
    double backConversion = account.convert(afterFee, to, from);
    double finalAmount = account.applyBankFee(backConversion);

    std::cout << "Direct conversion: " << amount << " " << from.code << " is equivalent to " << initialConversion << " " << to.code << "." << std::endl;
    std::cout << "After a 2% bank fee: " << amount << " " << from.code << " gives you " << afterFee << " " << to.code << "." << std::endl;
    std::cout << "Converting back after a 2% fee: " << afterFee << " " << to.code << " gives you " << finalAmount << " " << from.code << "." << std::endl;
}

int main() {
    std::map<std::string, Currency> currencies;

    try {
        std::ifstream file("CurrencyExchangeRates.txt");
        if (!file.is_open())
            throw std::runtime_error("Failed to open the file. Please check the file path.");

        std::string line;
        std::getline(file, line); // Skip first comment line
        std::getline(file, line); // Skip format description line

        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string currencyCode, currencyName;
            double usdToCurrency, currencyToUsd;
            if (!(iss >> currencyCode >> currencyName >> usdToCurrency >> currencyToUsd))
                throw std::runtime_error("File format incorrect.");

            currencies[currencyCode] = Currency(currencyCode, currencyName, usdToCurrency, currencyToUsd);
        }

        for (const auto& pair : currencies) {
            std::cout << pair.first << " (" << pair.second.name << ")" << std::endl;
        }

        BankAccount account;
        std::string fromCurrency, toCurrency;
        double amount;
        bool fromCurrencyValid = false, toCurrencyValid = false, amountValid = false;

        // Loop for entering currency code
        while (!fromCurrencyValid) {
            std::cout << "Enter the currency code you have: ";
            std::cin >> fromCurrency;
            fromCurrency = toUpperCase(fromCurrency);

            if (currencies.find(fromCurrency) == currencies.end()) {
                std::cout << "Currency code not found. Please try again.\n";
            }
            else {
                fromCurrencyValid = true;
            }
        }

        // Loop for entering amount
        std::string inputAmount;
        while (!amountValid) {
            std::cout << "Enter the amount you have: ";
            std::cin >> inputAmount;

            if (!isValidAmount(inputAmount, amount)) {
                std::cout << "Invalid amount entered. Please use only digits and a single decimal point.\n";
            }
            else {
                amountValid = true;
            }
        }

        // Loop for entering target currency code
        while (!toCurrencyValid) {
            std::cout << "Enter the currency code you want to convert to: ";
            std::cin >> toCurrency;
            toCurrency = toUpperCase(toCurrency);

            if (currencies.find(toCurrency) == currencies.end()) {
                std::cout << "Currency code not found. Please try again.\n";
            }
            else {
                toCurrencyValid = true;
            }
        }

        double convertedAmount = account.convert(amount, currencies[fromCurrency], currencies[toCurrency]);
        std::cout << amount << " " << fromCurrency << " is equivalent to " << convertedAmount << " " << toCurrency << "." << std::endl;

        displayBankExchange(account, amount, currencies[fromCurrency], currencies[toCurrency]);

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
