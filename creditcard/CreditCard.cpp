#include "CreditCard.h"

CreditCard::CreditCard(const std::string& no, const std::string& bnk, const std::string& nm, int lim, double bal) : number{no}, bank{bnk}, name{nm}, limit{lim}, balance{bal} {}

bool CreditCard::chargeIt(double price) {
	if(price + balance > double(limit))
		return false;
	balance += price;
	return true;
}

void CreditCard::makePayment(double payment) {
	balance -= payment;
}

std::ostream& operator<<(std::ostream& out, const CreditCard& c) {
	out << "Number = " << c.getNumber() << '\n'
		<< "Bank = " << c.getBank() << '\n'
		<< "Name = " << c.getName() << '\n'
		<< "Balance = " << c.getBalance() << '\n'
		<< "Limit = " << c.getLimit() << '\n';
	return out;
}