CC = g++
LINK = g++

simulated_annealing: main.o util.o calculations.o
	$(LINK) main.o util.o calculations.o -o simulated_annealing

main.o: main.cpp
	$(CC) -c main.cpp

util.o: util.cpp
	$(CC) -c util.cpp

calculations.o: calculations.cpp
	$(CC) -c calculations.cpp
