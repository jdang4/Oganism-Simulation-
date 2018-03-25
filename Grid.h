/*
 * Grid.h
 *
 *  Created on: Feb 23, 2018
 *      Author: jdang
 */

#ifndef GRID_H_
#define GRID_H_

#include <iostream>
#include <vector>

class Organism;

class Grid {

public:

	// Constructor
	Grid(int row, int column);

	// Destructor
	virtual ~Grid();

	// Data Members
	int row;
	int column;
	int totalAnts;
	int totalDoodles;

	// Function Members
	Organism ***bugGrid;
	bool isValid(int r, int c);
	int getRow();
	int getColumn();
	int getTotalNumOfAnts();
	int getTotalNumOfDoodles();
	void updateTotalNumOfAnts();
	void updateTotalNumOfDoodles();
	void printGrid(Grid* aGrid);

	std::vector<Organism*> getAllPrey();
	std::vector<Organism*> getAllPredator();
	std::vector<Organism*> getPrey(int r, int c);
	std::vector<Organism*> getPredator(int r, int c);
	std::vector<int*> getAllBlanks(int r, int c);


};



#endif /* GRID_H_ */
