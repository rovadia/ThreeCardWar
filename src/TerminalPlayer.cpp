/*
 * TerminalPlayer.cpp
 *
 *  Created on: Nov 22, 2016
 *      Author: student
 */

#include "TerminalPlayer.h"
using namespace std;

/*
 * Constructor
 */
TerminalPlayer::TerminalPlayer(string name): Player(name) {

}

/*
 * Player selects which card in hand to play
 */
const Card TerminalPlayer::playCard(const Card opponentCard) {
	if (opponentCard==Card()) {
		cout <<"You are going first"<<endl;
	}
	else {
		cout <<"Opponent plays "<<opponentCard<<endl;
	}
	cout<<"Your score is " << score<<endl;
	for (unsigned int i=0; i<hand.size(); i++) {
		cout<<"Card "<<i+1<< " is " <<hand[i]<<endl;
	}
	cout <<"Pick a card by typing number"<<endl;
	unsigned int index;
	while (!(cin>>index) || index<=0 || index>hand.size()) {
		cout <<"Invalid input, put valid number"<<endl;
		cin.clear();
	}
	index--;
	Card cardChosen=hand[index];
	hand.erase(hand.begin()+index);
	hand.begin();
	return cardChosen;
}

