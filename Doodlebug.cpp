/*
 * Doodlebug.cpp
 *
 *  Created on: Feb 23, 2018
 *      Author: jdang
 */

#include <iostream>
#include <cstdlib>
#include <vector>

#include "Doodlebug.h"
#include "Grid.h"
#include "Organism.h"


/**
 * The constructor
 *
 * @author Jonathan Dang
 */
Doodlebug::Doodlebug(Grid *gri, int rowPos, int colPos) : Organism(false, gri, rowPos, colPos) {
	eat = 0;
}

/**
 * The destructor
 *
 * @author Jonathan Dang
 */
Doodlebug::~Doodlebug() {

}

/**
 * This function is in charge of moving the doodlebug
 * @return It returns nothing
 *
 * @author Jonathan Dang
 */
void Doodlebug::move() {

	std::vector<Organism*> prey = grid->getPrey(rowPostion(), columnPosition());
	int size = prey.size();

	if (size != 0) {
		// generating a random location and storing the doodlebug object there
		Organism *location = prey.at((long)(rand() % size));
		int row1 = location->rowPostion();
		int col1 = location->columnPosition();

		location->die(); // this deletes the organism used to generater the random location

		// this updates the location of the organism on the field
		grid->bugGrid[location->rowPostion()][location->columnPosition()] = this;

		// sets the old position of the organism to NULL
		grid->bugGrid[rowPostion()][columnPosition()] = NULL;

		// updating the object's data fields
		r = row1;
		c = col1;
		eat = 0;
		breed();

		prey.clear();
	}

	else {

		// getting all the empty locations surrounding the doodlebug
		std::vector<int*> openSpaces = grid->getAllBlanks(rowPostion(), columnPosition());

		size = openSpaces.size();

		if (size != 0) {
			//generating a random direction for the doodlebug to travel
			int *location = openSpaces.at((long)(rand() % size));
			grid->bugGrid[location[0]][location[1]] = this;  // this moves the doodlebug to the new location
			grid->bugGrid[rowPostion()][columnPosition()] = NULL;  // this sets the previous location that the doodlebug was in to NULL

			// updates the doodlebug object field
			r = location[0];
			c = location[1];

			// checks if the doodlebug needs to die from starvation
			eat++;
			if (eat >= 3) {
				die();
			}

			else {
				breed();
			}

		}

		openSpaces.clear();

	}

}

/**
 * This function is in charge of breeding the doodlebug and spawning one nearby
 * @return It returns nothing
 *
 * @author Jonathan Dang
 */
void Doodlebug::breed() {

	breedCount++;

	if (breedCount >= 8) {

		// getting all the empty locations surrounding the ant
		std::vector<int*> openSpaces = grid->getAllBlanks(rowPostion(), columnPosition());

		// determines if there is a free location around the ant where it can breed to
		int size = openSpaces.size();

		if (size != 0) {
			// breeding the ant in a random direction
			int *location = openSpaces.at((long)(rand() % size));
			(new Doodlebug(grid, location[0], location[1]))->add();
			breedCount = 0;
		}
	}
}

