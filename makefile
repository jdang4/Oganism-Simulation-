CFLAGS = -g

all: PA5

PA5: main.o Grid.o Organism.o Ant.o Doodlebug.o
	g++ $(CFLAGS) -Wall main.o Grid.o Organism.o Ant.o Doodlebug.o -o PA5

main.o: main.cpp
	g++ $(CFLAGS) -Wall -c main.cpp

Grid.o: Grid.cpp Grid.h Organism.h
	g++ $(CFLAGS) -Wall -c Grid.cpp

Organism.o: Organism.cpp Organism.h Grid.h
	g++ $(CFLAGS) -Wall -c Organism.cpp

Ant.o: Ant.cpp Ant.h Organism.h Grid.h
	g++ $(CFLAGS) -Wall -c Ant.cpp

Doodlebug.o: Doodlebug.cpp Doodlebug.h Organism.h Grid.h
	g++ $(CFLAGS) -Wall -c Doodlebug.cpp

docs:
	doxygen

clean:
	rm -f main.o Grid.o Organism.o Ant.o Doodlebug.o PA5