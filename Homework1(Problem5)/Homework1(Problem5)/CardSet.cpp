#include <iostream>
#include "CardSet.h"
#include "newSet.h"
using namespace std;

CardSet::CardSet()
{
	//m_set;
}

bool CardSet::add(unsigned long cardNumber)
{
	// Add a card number to the CardSet.  Return true if and only if the
	// card number was actually added.
	return m_set.insert(cardNumber);
}

int CardSet::size() const
{
	// Return the number of card numbers in the CardSet.
	return m_set.size();
}

void CardSet::print() const
{
	unsigned long card = 0;
	for (int k = 0; k < size(); k++) {
		m_set.get(k, card);
		cout << card<< endl;
	}
}