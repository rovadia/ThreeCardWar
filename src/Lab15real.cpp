
#include <iostream>
#include "Deck.h"
#include "Card.h"
#include "TerminalPlayer.h"
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <stdexcept>
#include "SmartComputer.h"
using namespace std;

int main() {



	TerminalPlayer player1 = TerminalPlayer("Billy");
	SmartComputer player2 = SmartComputer("Bob");
	Deck deck1 = Deck();
	Card card1 = Card();
	deck1.shuffle();
	deck1.shuffle();
	deck1.shuffle();
	deck1.shuffle();
	deck1.shuffle();
	for (int i=0; i<3; i++) {  //refill hand with card from deck
		player1.receiveCard(deck1.draw());
		player2.receiveCard(deck1.draw());
	}

	int startPlayer = rand() % 2; //decide who plays first card in game
	if (startPlayer==0) {
		cout<< "Player 1 goes first"<<endl;
	}
	else {
		cout<<"Player 2 goes first"<<endl;
	}
	cout << "\n-------------------------------"<<endl;

	/*
	 * Game Loop
	 */
	while (player1.hasCards() && player2.hasCards() ) {
		Card player1Card=Card();
		Card player2Card=Card();
		if(startPlayer==0) {
			player1Card=player1.playCard(card1);
			player2Card=player2.playCard(player1Card);
		}
		else {
			player2Card=player2.playCard(card1);
			player1Card=player1.playCard(player2Card);
		}

		if (startPlayer==0) {
			cout << "Player1 played "<< player1Card<<endl;
			cout<< "Player2 played " <<player2Card<<endl;
		}
		else {
			cout<< "Player2 played " <<player2Card<<endl;
			cout << "Player1 played " << player1Card<<endl;
		}
		if (player1Card==player2Card) {
			cout <<"Tie this round"<<endl;
			player1.addScore(1);
			player2.addScore(1);
		}
		else if (player2Card<player1Card) {
			cout <<"Player 1 wins this round"<<endl;
			player1.addScore(2);
			startPlayer=0;
		}
		else if (player1Card<player2Card) {
			cout <<"Player 2 wins this round"<<endl;
			player2.addScore(2);
			startPlayer=1;
		}
		cout <<"\n-------------------------------------------"<<endl;

		if (!deck1.isEmpty() && startPlayer==0) {
			player1.receiveCard(deck1.draw());
			player2.receiveCard(deck1.draw());
		}
		else if (!deck1.isEmpty() && startPlayer==1) {
			player2.receiveCard(deck1.draw());
			player1.receiveCard(deck1.draw());
		}
	}

	/*
	 * Decide a winner
	 */
	int player1FinalScore = player1.getScore();
	int player2FinalScore = player2.getScore();
	if (player1FinalScore==player2FinalScore) {
		cout<<"Tie at end of game"<<endl;
	}
	else if (player1FinalScore<player2FinalScore) {
		cout <<"Player 2 wins at end of game"<<endl;
	}
	else {
		cout<< "Player 1 wins at end of game"<<endl;
	}


	return 0;
}
