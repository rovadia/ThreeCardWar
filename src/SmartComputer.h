/*
 * SmartComputer.h
 *
 *  Created on: Dec 4, 2016
 *      Author: student
 */

#ifndef SMARTCOMPUTER_H_
#define SMARTCOMPUTER_H_
#include "Player.h"

class SmartComputer: public Player {
public:

	/*
	 * Constructor
	 */
	SmartComputer(std::string name);

	/*
	 * playCard function
	 */
	const Card playCard(const Card opponentCard);


};

#endif /* SMARTCOMPUTER_H_ */
