/*
 * Card.cpp
 *
 *  Created on: Nov 14, 2016
 *      Author: student
 */

#include "Card.h"
//using namespace std;

/*
 * Constructor
 */
Card::Card() {
	cardSuit=Spades;
	cardRank=Joker;

}

/*
 * Constructor
 */
Card::Card(Suit newSuit, Rank newRank) {
	cardSuit=newSuit;
	cardRank=newRank;
}


/**
 * Less than operator override
 */
bool operator <(const Card&lhs, const Card&rhs)
{
	return (lhs.cardRank<rhs.cardRank);
}

/**
 * Equals operator override
 */
bool operator ==(const Card&lhs, const Card&rhs)
{
	return (lhs.cardRank==rhs.cardRank);
}

/*
 * << operator override
 */
std::ostream& operator <<(std::ostream& outputter, const Card& card) {
	if (card.cardRank==0) {
		return outputter<< rankNames[card.cardRank];
	}
	else {
		return outputter<< rankNames[card.cardRank]<< " of " << suitNames[card.cardSuit];
	}

}

