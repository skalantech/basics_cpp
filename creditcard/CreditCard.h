#ifndef CREDIT_CARD_H
#define CREDIT_CARD_H

#include <iostream>
#include <string>

class CreditCard {
public:
	CreditCard(const std::string& no, const std::string& bnk, const std::string& nm, int lim, double bal=0);
	virtual ~CreditCard() {}
	std::string getNumber() const { return number; }
	std::string getName() const { return name; }
	std::string getBank() const { return bank; }
	int getLimit() const { return limit; }
	double getBalance() const { return balance; }
	virtual bool chargeIt(double price);
	void makePayment(double payment);
private:
	std::string number;
	std::string bank;
	std::string name;
	int limit;
protected:
	double balance;
};

std::ostream& operator<<(std::ostream& out, const CreditCard& c);

#endif