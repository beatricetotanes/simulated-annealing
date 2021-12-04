CC = g++
LINK = g++

simulated_annealing: main.o helper.o calculations.o
	$(LINK) main.o helper.o calculations.o -o simulated_annealing

main.o: main.cpp
	$(CC) -c main.cpp

calculations.o: calculations.cpp
	$(CC) -c calculations.cpp

helper.o: helper.cpp
	$(CC) -c helper.cpp