#include "CreditCard.h"

class PredatoryCreditCard : public CreditCard {
public:
    PredatoryCreditCard(const std::string& nm, const std::string& bnk, const std::string& no, int lim, double rate, double bal=0);
    void process_month();
    virtual bool chargeIt(double price);
private:
    double apr;
};