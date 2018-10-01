/* Deck.cpp
 *
 *  Created on: Nov 14, 2016
 *      Author: student
 */

#include "Deck.h"
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <stdexcept>

using namespace std;

/*
 * Constructor
 */
Deck::Deck() {
	nextCard=0;
	for (int i=1; i<14; i++) {
		for (int j=0; j<4; j++) {
			cardDeck.push_back(Card(Card::Suit(j), Card::Rank(i)));
		}
	}
}

/*
 * Destructor
 */
Deck::~Deck() {
	// TODO Auto-generated destructor stub
}

/*
 * Check if deck is empty
 */
bool Deck::isEmpty() const {
	return nextCard==MaxCards;
}

/*
 * Shuffle deck using random shuffle
 */
void Deck::shuffle() {
	random_shuffle(cardDeck.begin(),cardDeck.end());
	nextCard=0;
}

/*
 * Draw card from the deck
 */
const Card Deck::draw() {
	if (isEmpty()==false) {
		nextCard++;
		return cardDeck[nextCard-1];
	}
	else {
		throw out_of_range("Deck empty");
	}
}

