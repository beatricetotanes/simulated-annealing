/**
 * @file main.cpp
 * @author Hermo, Andrew Louis and Totanes, Beatrice
 * @brief Performs simulated annealing based on the temperature schedule the user specifies.
 * @version 1.1
 * @date 2021-12-04
 * 
 * @copyright Copyright (c) 2021
 */

#include <iostream>
#include <limits>
#include <stdlib.h>
#include <ctime>
#include <deque>
#include <iterator>
#include "util.h"
#include "calculations.h"

int main(){

	static char schedule;
	static float reduxParam;
	static bool isTerminationMaxTAC;
	float initialTemp;
	std::deque<float> initialSolution = generateSeries();
	std::srand(time(0));

	while(1){
		std::cout << "\t---Simulated Annealing--\n" << std::endl;
		std::cout << "\t[1] Linear Schedule" << std::endl;
		std::cout << "\t[2] Geometric Schedule" << std::endl;
		std::cout << "\t[3] Slow Decrease" << std::endl;
		std::cout << "\t[0] Exit" << std::endl;
		std::cout << "Choice: ";
		std::cin >> schedule;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		std::cin.clear();

		switch(schedule){
			case '1':
				reduxParam = setTempReduxParam(true); 
				isTerminationMaxTAC = setTermCriterion();
				break;
			case '2':
				reduxParam = setTempReduxParam(true);
				isTerminationMaxTAC = setTermCriterion();
				break;
			case '3':
				reduxParam = setTempReduxParam(false);
				isTerminationMaxTAC = setTermCriterion();
				break;
			case '0':
				exit(1);
				break;
			default:
				std::cout << "Invalid input.\n";
				system("pause");
				system("cls");
				continue;
		}
		initialTemp = setInitialTemp();
		if(isTerminationMaxTAC){
			calcTrialsCycles(reduxParam, initialTemp, schedule, initialSolution);
		}else {
			calcFinalTemp(reduxParam, initialTemp, schedule, initialSolution);
		}
		system("pause");
		system("cls");
	}
}