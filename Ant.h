/*
 * Ant.h
 *
 *  Created on: Feb 23, 2018
 *      Author: jdang
 */

#ifndef ANT_H_
#define ANT_H_

#include "Organism.h"

class Grid;

class Ant: public Organism {

public:
	Ant(Grid *gri, int rowPos, int colPos);
	virtual ~Ant();

	virtual void move();
	virtual void breed();

};



#endif /* ANT_H_ */
