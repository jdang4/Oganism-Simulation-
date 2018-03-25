/*
 * Ant.cpp
 *
 *  Created on: Feb 23, 2018
 *      Author: jdang
 */

#include <iostream>
#include <cstdlib>
#include <vector>

#include "Ant.h"
#include "Grid.h"
#include "Organism.h"


/**
 * The constructor
 *
 * @Jonathan Dang
 */
Ant::Ant(Grid *gri, int rowPos, int colPos) : Organism(true, gri, rowPos, colPos) {

}

/**
 * The destructor
 *
 * @author Jonathan Dang
 */
Ant::~Ant() {

}

/**
 * This function is in charge of breeding an ant and spawning another ant object nearby
 * @return It returns nothing
 *
 * @author Jonathan Dang
 */
void Ant::breed() {

	breedCount++;

	if (breedCount >= 3) {

		// getting all the empty locations surrounding the ant
		std::vector<int*> openSpaces = grid->getAllBlanks(rowPostion(), columnPosition());

		// determines if there is a free location around the ant where it can breed to
		int size = openSpaces.size();

		if (size != 0) {
			// breeding the ant in a random direction
			int *location = openSpaces.at((long)(rand() % size));
			(new Ant(grid, location[0], location[1]))->add();
			breedCount = 0;
		}
	}
}

/**
 * This function is in charge of moving the ant
 * @return It returns nothing
 *
 * @author Jonathan Dang
 */
void Ant::move() {

	// getting all the empty locations surrounding the ant
	std::vector<int*> openSpaces = grid->getAllBlanks(rowPostion(), columnPosition());

	// determining if there is a free location around the ant that it could move in
	int size = openSpaces.size();

	if (size != 0) {
		//generating a random direction for the ant to travel
		int *location = openSpaces.at((long)(rand() % size));
		grid->bugGrid[location[0]][location[1]] = this;  // this moves the ant to the new location
		grid->bugGrid[rowPostion()][columnPosition()] = NULL;  // this sets the previous location that the ant was in to NULL

		// updates the ant object field
		r = location[0];
		c = location[1];
		breed();
	}

	openSpaces.clear();

}

