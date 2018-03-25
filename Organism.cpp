/*
 * Organism.cpp
 *
 *  Created on: Feb 23, 2018
 *      Author: jdang
 */

#include <iostream>
#include <cstdlib>
#include <vector>

#include "Organism.h"
#include "Grid.h"


/**
 * This is the constructor
 *
 * @author Jonathan Dang
 */
Organism::Organism(bool pre, Grid* gri, int rowPos, int colPos) {
	prey = pre;
	breedCount = 0;
	grid = gri;
	r = rowPos;
	c = colPos;

}

/**
 * This is the destructor
 *
 * @author Jonathan Dang
 */
Organism::~Organism() {

}

/**
 * This function is in charge of getting the prey variable of the Organism class
 * @return It returns the boolean value of the prey data member of Organism
 *
 * @author Jonathan Dang
 */
bool Organism::isPrey() {

	return prey;
}

/**
 * This function is in charge of returning the position of the row
 * @return It returns the integer value of the row position
 *
 * @author Jonathan Dang
 */
int Organism::rowPostion() {

	return r;
}

/**
 * This function is in charge of returning the position of the column
 * @return It returns the integer value of the column position
 *
 * @author Jonathan Dang
 */
int Organism::columnPosition() {

	return c;
}

/**
 * This function is in charge of deleting an object and it will set the location
 * of the object to NULL
 *
 * @return It returns nothing
 *
 * @author Jonathan Dang
 */
void Organism::die() {

	grid->bugGrid[r][c] = NULL;
	delete this;
}

/**
 * This function is in charge of adding an Organism object into the grid
 * @return It returns nothing
 *
 * @author Jonathan Dang
 */
void Organism::add() {

	// checks to see if the grid space of the organism is valid within the
	// bounds of the grid
	if (grid->isValid(r, c)) {
		grid->bugGrid[r][c] = this;
	}

	// checks if the organism is a doodlebug or an ant
	if (isPrey()) {
		grid->updateTotalNumOfAnts();
	}

	else {
		grid->updateTotalNumOfDoodles();
	}
}


