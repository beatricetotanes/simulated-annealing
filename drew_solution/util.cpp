#include <iostream>
#include <limits>
#include <random>
#include <deque>
#include <utility>
#include "util.h"

/**
 * @brief Sets the Temperature Reduction Parameter
 * 
 * @param isAlpha Checks if the user will use an alpha or beta for the parameter
 * @return the chosen Redux Parameter in float
 */
float setTempReduxParam(bool isAlpha){
	float val = 0.0;
	do{ // Loops until the user inputs a valid float value
		std::cout << "\t\nSpecify value of " << (isAlpha ? "alpha: " : "beta: ");
		std::cin >> val;
		if(!std::cin.fail()){
			break;
		}
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		std::cout << "Invalid input. Please try again." << std::endl;
	} while(1);
	return val;
}

/**
 * @brief Sets the Termination Criterion
 * 
 * @return True: if 'Max trials and cycles'\n False: if 'When temperature reaches final temperature'
 */
bool setTermCriterion(){
	char criterion;
	std::cout << "\nChoose the termination criterion to use" << std::endl;
	std::cout << "\t[a] Max trials and cycles" << std::endl;
	std::cout << "\t[b] When temperature reaches final temperature" << std::endl;
	while(1){ // Loops until the user inputs a valid char value
		std::cout << "Choice: ";
		std::cin >> criterion;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		std::cin.clear();
		switch(criterion){
			case 'a':
				return true;
			case 'b':
				return false;
			default:
				std::cout << "Invalid input. Please try again." << std::endl;
		}
	};
}

/**
 * @brief Get the trials and cycles from the user
 * 
 * @return A pair where the first is trials and second 1 is the cycles
 */
std::pair<int,int> setTrialsAndCycles(){
	std::pair<int,int> trialsAndCycles = std::make_pair(0,0);
	int input;
	while(!trialsAndCycles.second){
		std::cout << "\nEnter number of " << (!trialsAndCycles.first ? "trials: " : "cycles: ");
		std::cin >> input;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		std::cin.clear();
		if(std::cin.fail() || input < 1){
			std::cout << "Invalid input. Please try again." << std::endl;
			continue;
		}

		if(!trialsAndCycles.first){
			trialsAndCycles.first = input;
		}else {
			trialsAndCycles.second = input;
		}
	};
	return trialsAndCycles;
}

/**
 * @brief Set the initial temperature
 * 
 * @return The initial temperature in float
 */
float setInitialTemp(){
	float initialTemp = 0.0;
	while(1){
		std::cout << "\nEnter initial temperature: ";
		std::cin >> initialTemp;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		std::cin.clear();
		if(!std::cin.fail()){
			return initialTemp;
		}
		std::cout << "Invalid input. Please try again." << std::endl;
	};
}

/**
 * @brief Set the final temperature
 * 
 * @param initialTemp The initial temperature to compare to the final temperature 
 * @return The final temperature in float
 */
float setFinalTemp(float initialTemp){
	float finalTemp = 0.0;
	while(1){
		std::cout << "\nEnter final temperature: ";
		std::cin >> finalTemp;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		std::cin.clear();
		if(initialTemp < finalTemp){
			std::cout << "Final temperature must be lower than initial temperature ("<< initialTemp <<")" << std::endl;
			continue;
		}else if(std::cin.fail()){
			std::cout << "Invalid input. Please try again." << std::endl;
			continue;
		}
		return finalTemp;
	}
}
