#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>

double applyBankFee(double amount) {
    return amount * 0.98; // Deducting 2% fee
}

int main() {
    std::map<std::string, std::pair<double, double>> exchangeRates;
    std::map<std::string, std::string> currencyNames;
    std::ifstream file("CurrencyExchangeRates.txt");
    std::string line;

    if (!file.is_open()) {
        std::cout << "Failed to open the file. Please check the file path." << std::endl;
        return 1; // Exit if the file cannot be opened
    }

    // Skip header lines
    std::getline(file, line); // Skip first comment line
    std::getline(file, line); // Skip format description line

    // Read currency exchange rates and names into the maps
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string currencyCode, currencyName;
        double usdToCurrency, currencyToUsd;
        if (!(iss >> currencyCode >> currencyName >> usdToCurrency >> currencyToUsd)) { break; } // error

        exchangeRates[currencyCode] = { usdToCurrency, currencyToUsd };
        currencyNames[currencyCode] = currencyName;
    }

    // Display available currencies
    std::cout << "Available currencies:" << std::endl;
    for (const auto& currency : currencyNames) {
        std::cout << currency.first << " (" << currency.second << ")" << std::endl;
    }

    std::string fromCurrency, toCurrency;
    double amount;

    // Get user input
    std::cout << "Enter the currency code you have: ";
    std::cin >> fromCurrency;
    std::cout << "Enter the amount you have: ";
    std::cin >> amount;
    std::cout << "Enter the currency code you want to convert to: ";
    std::cin >> toCurrency;

    // Perform conversion
    if (exchangeRates.find(fromCurrency) == exchangeRates.end() || exchangeRates.find(toCurrency) == exchangeRates.end()) {
        std::cout << "Currency code not found. Please check your input." << std::endl;
    }
    else {
        double fromRate = exchangeRates[fromCurrency].second; // Get the rate from currency to USD
        double toRate = exchangeRates[toCurrency].first; // Get the rate from USD to the target currency

        // Direct conversion
        double usdAmount = amount * fromRate; // Convert from 'fromCurrency' to USD
        double convertedAmount = usdAmount * toRate; // Convert from USD to 'toCurrency'
        std::cout << amount << " " << fromCurrency << " is equivalent to " << convertedAmount << " " << toCurrency << "." << std::endl;

        // Conversion with bank fees
        double reducedAmount = applyBankFee(convertedAmount); // Apply bank fee on first conversion
        std::cout << "After converting " << amount << " " << fromCurrency << " to " << toCurrency << " with a 2% bank fee, you get " << reducedAmount << " " << toCurrency << "." << std::endl;

        double backToUsd = reducedAmount * exchangeRates[toCurrency].second; // Convert back to USD
        double finalAmount = backToUsd * exchangeRates[fromCurrency].first; // Convert back to original currency
        finalAmount = applyBankFee(finalAmount); // Apply bank fee on second conversion
        std::cout << "Converting " << reducedAmount << " " << toCurrency << " back to " << fromCurrency << " with a 2% bank fee, you get " << finalAmount << " " << fromCurrency << "." << std::endl;
    }

    return 0;
}