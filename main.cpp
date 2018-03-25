/*
 * main.cpp
 *
 *  Created on: Feb 23, 2018
 *      Author: jdang
 */

#include <iostream>
#include <cstdlib>
#include <stdlib.h>

#include "Grid.h"
#include "Organism.h"
#include "Ant.h"
#include "Doodlebug.h"

using namespace std;

int main(int argc, char *argv[]) {

	// default values
	int gridSize = 20;
	int doodlebugs = 5;
	int ants = 100;
	int time_steps = 1000;
	int seed = 1;
	int pause = 0;

	if (argc >= 2) {
		gridSize = atoi(argv[1]);
	}

	if (gridSize <= 0) {
		cout << "Invalid grid size" << endl;
		exit(0);
	}

	if (argc >= 3) {
		doodlebugs = atoi(argv[2]);
	}

	if (doodlebugs < 0) {
		cout << "Number of Doodlebugs has to be a positive value" << endl;
		exit(0);
	}
	if (argc >= 4) {
		ants = atoi(argv[3]);
	}

	if (ants < 0) {
		cout << "Number of Ants has to be a positive value" << endl;
		exit(0);
	}

	if (argc >= 5) {
		time_steps = atoi(argv[4]);
	}

	if (time_steps <= 0) {
		cout << "The value of time steps has to be greater than 0" << endl;
		exit(0);
	}

	if (argc >= 6) {
		seed = atoi(argv[5]);
	}

	if (seed < 0) {
		cout << "The value of seed has to be greater than 0" << endl;
		exit(0);
	}

	if (argc >= 7) {
		pause = atoi(argv[6]);
	}

	if (pause < 0) {
		cout << "The value of pause has to be greater than or equaled to 0" << endl;
		exit(0);
	}

	if ((gridSize * gridSize) < (doodlebugs + ants)) {
		cout << "Too many doodlebugs entered" << endl;
		exit(1);
	}

	srand(seed);

	Grid *playGrid = new Grid(gridSize, gridSize);

	// adding the doodlebugs to the grid at random locations
	for (int i = 0; i < doodlebugs; i++) {
		// generating a random row and column location
		int rowOrganism = rand() % gridSize;
		int columnOrganism = rand() % gridSize;

		// while the row and column location is not empty, keep generating
		// new rows and columns
		while (playGrid->bugGrid[rowOrganism][columnOrganism] != NULL) {
			rowOrganism = rand() % gridSize;
			columnOrganism = rand() %gridSize;
		}

		// Loop Invariant: at this point, elements from 0 to i - 1 have been added randomly into the grid

		// instantiating a doodlebug object with a random location and adding it to the grid
		(new Doodlebug(playGrid, rowOrganism, columnOrganism))->add();
	}

	// adding the and to the grid at random locations
	for (int i = 0; i < ants; i++) {
		// generating a random row and column location
		int rowOrganism = rand() % gridSize;
		int columnOrganism = rand() % gridSize;

		// while the row and column location is not empty, keep generating
		// new rows and columns
		while (playGrid->bugGrid[rowOrganism][columnOrganism] != NULL) {
			rowOrganism = rand() % gridSize;
			columnOrganism = rand() %gridSize;
		}

		// Loop Invariant: at this point, elements from 0 to i - 1 have been added randomly into the grid

		// instantiating a doodlebug object with a random location and adding it to the grid
		(new Ant(playGrid, rowOrganism, columnOrganism))->add();
	}

	std::vector<Organism*> predator = playGrid->getAllPredator();
	std::vector<Organism*> prey = playGrid->getAllPrey();

	int doodlebugSize = predator.size();
	int antSize = prey.size();
	int tStep = 0;
	int pauseLoop = 0;


	// running the actual program

	while (doodlebugSize > 0 && antSize > 0 && tStep < time_steps) {

		if (pause != 0) {
			if (pauseLoop % pause == 0 && pauseLoop != 0) {
				cout << endl;
				cout << "Grid: " << tStep << endl;
				playGrid->printGrid(playGrid);
				cin.get();
			}

			pauseLoop++;
		}

		// moving each predator
		for (int i = 0; i < doodlebugSize; i++) {

			// Loop Invariant: at this point, elements from 0 to i - 1 have moved
			predator.at(i)->move();
		}

		// updating the number of prey
		prey = playGrid->getAllPrey();
		antSize = prey.size();

		// moving each prey
		for (int i = 0; i < antSize; i++) {

			// Loop Invariant: at this point, elements from 0 to i - 1 have moved
			prey.at(i)->move();
		}

		predator.clear();
		prey.clear();


		predator = playGrid->getAllPredator();
		doodlebugSize = predator.size();
		tStep++;

	}

	cout << endl;
	cout << "Grid " << tStep << " (Final Grid)" << endl;

	if (tStep != 0) {
		playGrid->printGrid(playGrid);
	}
	cout << endl;

	cout << "Statistics: " << endl;
	cout << "User Input for Grid Size: " << gridSize << endl;
	cout << "User Input for Number of Doodlebugs: " << doodlebugs << endl;
	cout << "User Input for Number of Ants: " << ants << endl;
	cout << "User Input for Number of Time Steps: " << time_steps << endl;
	cout << "User Input for Value of Seed: " << seed << endl;
	cout << "User Input for Value of Pause: " << pause << endl;
	cout << endl;
	cout << "Total Number of Steps: " << tStep << endl;
	cout << "Total Number of Ants: " << playGrid->getTotalNumOfAnts() << endl;
	cout << "Number of Ants Remaining: " << playGrid->getAllPrey().size() << endl;
	cout << "Total Number of Doodlebugs: " << playGrid->getTotalNumOfDoodles() << endl;
	cout << "Number of Doodlebugs Remaining: " << doodlebugSize << endl;
	cout << endl;

}






