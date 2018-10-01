/*
 * TerminalPlayer.h
 *
 *  Created on: Nov 22, 2016
 *      Author: student
 */

#ifndef TERMINALPLAYER_H_
#define TERMINALPLAYER_H_
#include "Player.h"

class TerminalPlayer: public Player {
public:

	/*
	 * Constructor
	 */
	TerminalPlayer(std::string name);

	/*
	 * playCard function
	 */
	const Card playCard(const Card opponentCard);


};

#endif /* TERMINALPLAYER_H_ */
