#include "PredatoryCreditCard.h"
#include <cmath>

PredatoryCreditCard::PredatoryCreditCard(const std::string& nm, const std::string& bnk, const std::string& no, int lim, double rate, double bal) : CreditCard(nm, bnk, no, lim, bal), apr{rate} {
    std::cout << "Predatory card created\n";
}

bool PredatoryCreditCard::chargeIt(double price) {
    bool success = CreditCard::chargeIt(price);
    if(!success) {
        balance += 5;
        std::cout << "penalty charged\n";
    }
    return success;
}

void PredatoryCreditCard::process_month() {
    if(balance > 0) {
        double monthly_factor = pow(1 + apr, 1.0/12);
        balance *= monthly_factor;
    }
}