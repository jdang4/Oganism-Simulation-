/*
 * Doodlebug.h
 *
 *  Created on: Feb 23, 2018
 *      Author: jdang
 */

#ifndef DOODLEBUG_H_
#define DOODLEBUG_H_

#include "Organism.h"

class Grid;

class Doodlebug : public Organism {
	int eat;

public:
	Doodlebug(Grid *gri, int rowPos, int colPos);

	virtual void move();
	virtual void breed();
	virtual ~Doodlebug();
};



#endif /* DOODLEBUG_H_ */
