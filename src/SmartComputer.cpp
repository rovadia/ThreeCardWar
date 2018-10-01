/*
 * SmartComputer.cpp
 *
 *  Created on: Dec 4, 2016
 *      Author: student
 */

#include "SmartComputer.h"
using namespace std;


/*
 * Constructor
 */
SmartComputer::SmartComputer(string name): Player(name) {

}

/*
 * Computer plays card intelligently
 */
const Card SmartComputer::playCard(const Card opponentCard) {
	Card chosenCard;
	unsigned int index;
	if (hand[0]<opponentCard && hand[1]<opponentCard && hand[2]<opponentCard) { //opponent has you beat, pick lowest card
		if (hand[0]<hand[1] && hand[0]<hand[2]) {
			chosenCard = hand[0];
			index=0;
		}
		else if (hand[0]<hand[1] && hand[0]==hand[2]) { //if hand is 3,3,4 for example
			chosenCard=hand[0];
			index=0;
		}
		else if (hand[0]<hand[2] && hand[0]==hand[1]) { //if hand is 3,3,4 for example
			chosenCard=hand[0];
			index=0;
		}
		else if (hand[1]<hand[0] && hand[1]==hand[2]) { //if hand is 3,3,4 for example
			chosenCard=hand[1];
			index=1;
		}
		else if (hand[1]==hand[2] && hand[2]==hand[0]) { //if hand is 3,3,3, for example
			chosenCard=hand[0];
			index=0;
		}
		else if (hand[1]<hand[2]&&hand[1]<hand[0]) {
			chosenCard = hand[1];
			index=1;
		}
		else if (hand[2]<hand[1] && hand[2]<hand[0]) {
			chosenCard = hand[2];
			index=2;
		}
	}
	else if (opponentCard<hand[0]&&opponentCard<hand[1]&&opponentCard<hand[2]) { //if all 3 hand cards beat opponentcard
		if (hand[0]<hand[1] && hand[0]<hand[2]) {
					chosenCard = hand[0];
					index=0;
		}
		else if (hand[0]<hand[1] && hand[0]==hand[2]) { //if hand is 2,2,3 for example
			chosenCard=hand[0];
			index=0;
		}
		else if (hand[0]<hand[2] && hand[0]==hand[1]) { //if hand is 2,2,3 for example
			chosenCard=hand[0];
			index=0;
		}
		else if (hand[1]<hand[0] && hand[1]==hand[2]) { //if hand is 2,2,3 for example
			chosenCard=hand[1];
			index=1;
		}
		else if (hand[1]==hand[2]&&hand[1]==hand[0]) { //if hand is 3,3,3, for example
			chosenCard=hand[0];
			index=0;
		}
		else if (hand[1]<hand[2]&&hand[1]<hand[0]) {
			chosenCard = hand[1];
			index=1;
		}
		else if (hand[2]<hand[1]&&hand[2]<hand[0]) {
			chosenCard = hand[2];
			index=2;
		}
	}
	else if (opponentCard<hand[0]&&opponentCard<hand[1]) {
		if (hand[0]<hand[1]) {
			chosenCard = hand[0];
			index=0;
		}
		else if (hand[1]<hand[0]) {
			chosenCard = hand[1];
			index=1;
		}
		else if (hand[1]==hand[0]) {
			chosenCard = hand[1];
			index=1;
		}
	}
	else if (opponentCard<hand[1] && opponentCard<hand[2]) {
		if (hand[1]<hand[2]) {
			chosenCard = hand[1];
			index=1;
		}
		else if (hand[2]<hand[1]) {
			chosenCard = hand[2];
			index=2;
		}
		else if (hand[2]==hand[1]) {
			chosenCard = hand[1];
			index=1;
		}
	}
	else if (opponentCard<hand[0] && opponentCard<hand[2]) {
		if (hand[0]<hand[2]) {
			chosenCard = hand [0];
			index=0;
		}
		else if (hand[2]<hand[0]) {
			chosenCard = hand[2];
			index=2;
		}
		else if (hand[2]== hand[0]) {
			chosenCard = hand[2];
			index=2;
		}
	}
	else if (opponentCard<hand[0]) {
		chosenCard = hand[0];
		index=0;
	}
	else if (opponentCard<hand[1]) {
		chosenCard = hand[1];
		index=1;
	}
	else if (opponentCard<hand[2]) {
		chosenCard = hand[2];
		index=2;
	}
	else if (opponentCard==hand[0]) {
		chosenCard = hand[0];
		index=0;
	}
	else if (opponentCard==hand[1]) {
		chosenCard = hand[1];
		index=1;
	}
	else if (opponentCard==hand[2]) {
		chosenCard = hand[2];
		index=2;
	}

	if (opponentCard== Card()) { //if going first, play lowest card
		if (hand[0]<hand[1] && hand[0]<hand[2]) {
			chosenCard = hand[0];
			index=0;
		}
		else if (hand[0]<hand[1] && hand[0]==hand[2]) { //if hand is 3,3,4 for example
			chosenCard=hand[0];
			index=0;
		}
		else if (hand[0]<hand[2] && hand[0]==hand[1]) { //if hand is 3,3,4 for example
			chosenCard=hand[0];
			index=0;
		}
		else if (hand[1]<hand[0] && hand[1]==hand[2]) { //if hand is 3,3,4 for example
			chosenCard=hand[1];
			index=1;
		}
		else if (hand[1]==hand[2] && hand[2]==hand[0]) { //if hand is 3,3,3, for example
			chosenCard=hand[0];
			index=0;
		}
		else if (hand[1]<hand[2]&&hand[1]<hand[0]) {
			chosenCard = hand[1];
			index=1;
		}
		else if (hand[2]<hand[1] && hand[2]<hand[0]) {
			chosenCard = hand[2];
			index=2;
		}
	}

	hand.erase(hand.begin()+index);
	hand.begin();
	cout<<"Computer score is " << score<<endl;
	return chosenCard;
}

