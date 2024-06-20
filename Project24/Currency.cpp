#include "Currency.h"

Currency::Currency() : code(""), name(""), toUSD(0.0), fromUSD(0.0) {}

Currency::Currency(std::string c, std::string n, double t, double f) : code(c), name(n), toUSD(t), fromUSD(f) {}

Currency::Currency(const Currency &other) : code(other.code), name(other.name), toUSD(other.toUSD),
                                            fromUSD(other.fromUSD) {}

Currency::~Currency() {}


