/*
 * Organism.h
 *
 *  Created on: Feb 23, 2018
 *      Author: jdang
 */

#ifndef ORGANISM_H_
#define ORGANISM_H_

class Grid;

class Organism {

public:

	// Constructor
	Organism(bool prey, Grid *grid, int rowPos, int colPos);

	// Destructor
	virtual ~Organism();

	// Data Members
	bool prey;
	int breedCount;
	Grid *grid;
	int r;      // row
	int c;      // column


	// Function Members
	bool isPrey();
	virtual void move() = 0;   // a pure virtual function (has to be overridden)
	virtual void breed() = 0;  // a pure virtual function (has to be overridden)
	void die();
	int rowPostion();
	int columnPosition();
	void add();

};



#endif /* ORGANISM_H_ */
