/*
 * Grid.cpp
 *
 *  Created on: Feb 23, 2018
 *      Author: jdang
 */

#include <iostream>
#include <cstdlib>
#include <vector>

#include "Grid.h"
#include "Organism.h"

using namespace std;

/**
 * The constructor
 *
 * @author Jonathan Dang
 */
Grid::Grid(int r, int col) : row(r), column(col), totalAnts(0), totalDoodles(0), bugGrid(new Organism**[r]) {

	// inputing Organisms into the array
	for (int c = 0; c < r; c++) {
		bugGrid[c] = new Organism*[col];
	}
}

/**
 * The destructor
 *
 * @author Jonathan Dang
 */
Grid::~Grid() {

}

/**
 * This function is in charge of printing out the grid
 * @return It doesn't return anything
 *
 * @author Jonathan Dang
 */
void Grid::printGrid(Grid *aGrid) {
	int i;
	int j;
	for (i = 0; i < aGrid->getRow(); i++) {
		cout << endl;
		for (j = 0; j < aGrid->getColumn(); j++) {
			if (aGrid->bugGrid[i][j] == NULL) {
				cout << " ";
			}

			else if (aGrid->bugGrid[i][j]->isPrey()) {
				cout << "o ";
			}

			else if (!aGrid->bugGrid[i][j]->isPrey()) {
				cout << "x ";
			}
		}
	}

	cout << endl;
}

/**
 * This function is in charge of determining if the certain location is off the end of the grid
 * @param r It is the specific row that is being looked at
 * @param c It is the specific column that is being looked at
 * @return It returns a boolean (true if it is valid and false if it isn't valid)
 *
 * @author Jonathan Dang
 */
bool Grid::isValid(int r, int c) {

	// makes sure the value of r and c arent't off the grid
	if (r >= 0 && r < row && c >= 0 && c < column) {

		return true;
	}

	return false;
}

/**
 * It obtains the row data member value from Grid class
 * @return It returns the value of row
 *
 * @author Jonathan Dang
 */
int Grid::getRow() {

	return row;
}

/**
 * It obtains the column data member value from Grid class
 * @return It returns the value of column
 *
 * @author Jonathan Dang
 */
int Grid::getColumn() {

	return column;
}

/**
 * It obtains the totalAnts data member value from Grid class
 * @return It returns the value of totalAnts
 *
 * @author Jonathan Dang
 */
int Grid::getTotalNumOfAnts() {

	return totalAnts;
}

/**
 * It obtains the totalColumns data member value from Grid class
 * @return It returns the value of totalColumns
 *
 * @author Jonathan Dang
 */
int Grid::getTotalNumOfDoodles() {

	return totalDoodles;
}

/**
 * This function is in charge of increasing the value of totalAnts by one
 * @return It returns nothing
 *
 * @author Jonathan Dang
 */
void Grid::updateTotalNumOfAnts() {

	totalAnts++;
}

/**
 * This function is in charge of increasing the value of totalDoodles by one
 * @return it returns nothing
 *
 * @author Jonathan Dang
 */
void Grid::updateTotalNumOfDoodles() {

	totalDoodles++;
}

/**
 * This function is in charge of putting all the preys within the grid into a vector
 * @return It returns the vector the contains all the preys within the grid
 *
 * @author Jonathan Dang
 */
std::vector<Organism*> Grid::getAllPrey() {

	std::vector<Organism*> allPreys;

	for (int r = 0; r < row; r++) {
		for (int c = 0; c < column; c++) {
			if (bugGrid[r][c] != NULL) {
				if (bugGrid[r][c]->isPrey()) {

					// Loop Invariant: at this point, elements from 0 to r and c that are a prey have
					//  been added into the vector

					// because the space is a prey, it adds it to end of allPreys vector
					allPreys.push_back(bugGrid[r][c]);
				}
			}
		}
	}

	return allPreys;
}

/**
 * This function is in charge of putting all the preys within the grid into a vector
 * @param r This is the maximum number of rows in the grid
 * @param c This is the maximum number of columns in the grid
 * @return this returns the vector containing all the preys within the grid space
 *
 * @author Jonathan Dang
 */
std::vector<Organism*> Grid::getPrey(int r, int c) {

	std::vector<Organism*> allPreys;

	// avoids going off the grid
	if ((r - 1) >= 0) {
		// checking the left side
		if ( (bugGrid[r - 1][c] != NULL) && (bugGrid[r - 1][c]->isPrey()) ) {

			allPreys.push_back(bugGrid[r - 1][c]);
		}
	}

	// avoids going off the grid
	if ((r + 1) < row) {
		// checks the right side
		if ( (bugGrid[r + 1][c] != NULL) && (bugGrid[r + 1][c]->isPrey()) ) {

			allPreys.push_back(bugGrid[r + 1][c]);
		}
	}

	// avoids going off the grid
	if ((c - 1) >= 0) {
		// checking the top side
		if ( (bugGrid[r][c - 1] != NULL) && (bugGrid[r][c - 1]->isPrey()) ) {

			allPreys.push_back(bugGrid[r][c - 1]);
		}
	}

	// avoids going off the grid
	if ((c + 1) < column) {
		// checks the bottom side
		if ( (bugGrid[r][c + 1] != NULL) && (bugGrid[r][c + 1]->isPrey()) ) {

			allPreys.push_back(bugGrid[r][c + 1]);
		}
	}

	return allPreys;
}

/**
 * This function is in charge of putting all the predator within the grid into a vector
 * @reutrn It returns the vector containing all the predators within the grid space
 *
 * @author Jonathan Dang
 */
std::vector<Organism*> Grid::getAllPredator() {

	std::vector<Organism*> allPredators;

	for (int r = 0; r < row; r++) {
		for (int c = 0; c < column; c++) {
			if (bugGrid[r][c] != NULL) {
				if (!(bugGrid[r][c]->isPrey())) {

					// Loop Invariant: at this point, elements from 0 to r and c that are a prey have
					//  been added into the vector

					// because the space is a predator, it adds it to end of allPredator vector
					allPredators.push_back(bugGrid[r][c]);
				}
			}
		}
	}

	return allPredators;
}

/**
 * This function is in charge of putting all the predators within the grid into a vector
 * @param r This is the maximum number of rows in the grid
 * @param c This is the maximum number of columns in the grid
 * @return this returns the vector containing all the predators within the grid space
 *
 * @author Jonathan Dang
 */
std::vector<Organism*> Grid::getPredator(int r , int c) {

	std::vector<Organism*> allPredators;

	// avoids going off the grid
	if ((r - 1) >= 0) {
		// checking the left side
		if ( (bugGrid[r - 1][c] != NULL) && ( !(bugGrid[r - 1][c]->isPrey()) )) {

			allPredators.push_back(bugGrid[r - 1][c]);
		}
	}

	// avoids going off the grid
	if ((r + 1) < row) {
		// checks the right side
		if ( (bugGrid[r + 1][c] != NULL) && ( !(bugGrid[r + 1][c]->isPrey()) )) {

			allPredators.push_back(bugGrid[r + 1][c]);
		}
	}

	// avoids going off the grid
	if ((c - 1) >= 0) {
		// checking the top side
		if ( (bugGrid[r][c - 1] != NULL) && ( !(bugGrid[r][c - 1]->isPrey()) )) {

			allPredators.push_back(bugGrid[r][c - 1]);
		}
	}

	// avoids going off the grid
	if ((c + 1) < column) {
		// checks the bottom side
		if ( (bugGrid[r][c + 1] != NULL) && ( !(bugGrid[r][c + 1]->isPrey()) )) {

			allPredators.push_back(bugGrid[r][c + 1]);
		}
	}

	return allPredators; 
}

/**
 * This function is in charge of putting all the empty locations in the grid into a vector
 * @param r It is the maximum number of rows within the grid
 * @param c It is the maximum number of columns within the grid
 * @return It returns the vector that contains all the empty spaces
 *
 * @author Jonathan Dang
 */
std::vector<int*> Grid::getAllBlanks(int r, int c) {

	std::vector<int*> allEmptys;

	// checks the left side
	if ((r - 1) >= 0) {
		if (bugGrid[r - 1][c] == NULL) {
			// creating a pointer that points to an array of ints
			int* location1 = new int[2];
			location1[0] = r - 1;
			location1[1] = c;

			allEmptys.push_back(location1);
		}
	}

	//checks the right side
	if ((r + 1) < row) {
		if (bugGrid[r + 1][c] == NULL) {
			// creating a pointer that points to an array of ints
			int* location2 = new int[2];
			location2[0] = r + 1;
			location2[1] = c;

			allEmptys.push_back(location2);
		}
	}

	//checks the top side
	if ((c - 1) >= 0) {
		if (bugGrid[r][c - 1] == NULL) {
			// creating a pointer that points to an array of ints
			int* location3 = new int[2];
			location3[0] = r;
			location3[1] = c - 1;

			allEmptys.push_back(location3);
		}
	}

	// checks the bottom side
	if ((c + 1) < column) {
		if (bugGrid[r][c + 1] == NULL) {
			// creating a pointer that points to an array of ints
			int* location4 = new int[2];
			location4[0] = r;
			location4[1] = c + 1;

			allEmptys.push_back(location4);
		}
	}

	return allEmptys;
}
