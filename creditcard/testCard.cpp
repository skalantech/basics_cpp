#include "PredatoryCreditCard.h"

#include <vector>

void testCard() {
	std::vector<CreditCard*> wallet;
	
	auto* card1 = new CreditCard("John Bowman", "California Servings", "5391 0375 9387 5309", 5000);
	auto* card2 = new CreditCard("Jake Brown", "California Federal", "3485 0399 3395 1954", 3500);
	auto* card3 = new CreditCard("Carl Nelson", "Banesco", "6011 4902 3294 2994", 2500, 300);
	auto* card4 = new PredatoryCreditCard("Gabriel Fuccua", "Banco Mercantil", "5390 0475 9687 3309", 1500, 0.825, 1300);

	wallet.push_back(card1);
	wallet.push_back(card2);
	wallet.push_back(card3);
	wallet.push_back(card4);

	auto* wallet_predatory = dynamic_cast<PredatoryCreditCard*>(wallet[3]);
	wallet_predatory->chargeIt(300);
	std::cout << *wallet_predatory << '\n';
	wallet_predatory->process_month();
	std::cout << "After processing month:\n";
	std::cout << *wallet_predatory << '\n';

	for(int i = 0; i <= 16; i++) {
		wallet[0]->chargeIt(double(i));
		wallet[1]->chargeIt(2 * i);
		wallet[2]->chargeIt(double(3 * i));
		wallet_predatory->chargeIt(double(i/2));
	}

	std::cout << "Card payments:\n";

	for(auto& card : wallet) {
		std::cout << *card << '\n';
		while(card->getBalance() > 100.0) {
			card->makePayment(100.0);
			std::cout << "New balance = " << card->getBalance() << '\n';
		}
		for(long unsigned int i = 0; i < 2 * card->getName().size(); i++) {
			std::cout << "=";
		}
		std::cout << '\n';
		delete card;
	}
}

int main() {
	testCard();
	return EXIT_SUCCESS;
}