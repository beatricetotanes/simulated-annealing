#include <iostream>
#include <deque>
#include <random>
#include <math.h>
#include <ctime>
#include <iomanip>
#include <iterator>
#include "util.h"
#include "calculations.h"

/**
 * @brief Generates a series of random values as a possible solution set
 * 
 * @param isInitial Checks if the series is the initial generation
 * @return a deque of float which contains a new solution set 
 */
std::deque<float> generateSeries(bool isInitial){
	std::deque<float> solution;
	for(int i = 0; i < 5; i++){
		solution.push_back(griewankGenerate(-5.0,5.0) - (isInitial ? 0 : 0.5));
	}
	return solution;
}

/**
 * @brief Generates a random value in the range of the lower bound and upper bound
 * 
 * @param lb The lower bound value 
 * @param ub The upper bound value
 * @return a random float value
 */
float griewankGenerate(float lb, float ub){
	float randomNumber = (float)(rand())/((float)(RAND_MAX));
	return (float) lb + randomNumber*(ub - lb);
}

/**
 * @brief Performs the griewank equation on the list of solutions.
 * 
 * @param solution The solution set that the griewank function performs on
 * @return a float value of the solution from the griewank equation
 */
float griewank(std::deque<float> solution){
	float summation = 0.0;
	float product = 1.0;
	int length = solution.size();
	for(int i = 0; i < length; i++){
		summation += (solution.at(i) * solution.at(i))/4000;
		product *= std::cos(solution.at(i)/(float)std::sqrt(i+1));
	}
	return summation - product + 1;
}

/**
 * @brief Calculates the probability of a worst solution
 * 
 * @param delta_f The change from initial point to a new point
 * @param T The temperature
 * @return the probability of acceptance
 */
float getProbability(float delta_f, float T){
	return std::exp(-1 * (delta_f/T));
}

/**
 * @brief Determines new temperature based on annealing schedules
 * 
 * @param schedule May either be [1] Linear Schedule, [2] Geometric Schedule, [3] Slow Decrease
 * @param prevTemp The previous temperature
 * @param reduxParam The reduction parameter
 * @return The float value of the new base temperature
 */
float changeTemp(char schedule, float prevTemp, float reduxParam){
	switch(schedule){
		case '1':
			return (float)prevTemp - (float)reduxParam;
		case '2':
			return prevTemp * reduxParam;
		default:
			return prevTemp / (1 + (reduxParam * prevTemp));
	}
}

/**
 * @brief Performs simulated annealing via max trials and cycles
 * 
 * @param reduxParam The reduction parameter 
 * @param initialTemp The initial temperature
 * @param schedule May either be [1] Linear Schedule, [2] Geometric Schedule, [3] Slow Decrease
 * @param solution The initial solution set 
 */
void calcTrialsCycles(float reduxParam, float initialTemp, char schedule, std::deque<float> solution){
	std::pair<int,int> trialsAndCycles = setTrialsAndCycles();
	std::deque<float> newSolution;
	float ofv_solution, ofv_new_solution, delta_f, probability, z;
	for(int cycle = 1; cycle <= trialsAndCycles.second; ++cycle){
		std::cout << "[Cycle: " << cycle << "] [Temperature: " << initialTemp << "]" << std::endl;
		std::cout << "Object Function Value is: " << griewank(solution) << "\n\n";
		for(int trial = 1; trial <= trialsAndCycles.first; ++trial){
			newSolution = generateSeries(false);

			ofv_solution = griewank(solution);
			ofv_new_solution = griewank(newSolution);

			delta_f = ofv_new_solution - ofv_solution;

			if(delta_f < 0){
				solution = newSolution;
			}else {
				probability = getProbability(delta_f, initialTemp);
				z = griewankGenerate(0,1);
				if(z < probability){
					solution = newSolution;
				}
			}
		}
		initialTemp = changeTemp(schedule, initialTemp, reduxParam);
	}

	std::cout << "Final Solution: " << griewank(solution) << std::endl;
	std::cout << "Solution set: [ ";
	for(float val: solution){
		std::cout << val << " ";
	}
	std::cout << "]" << std::endl;
}

/**
 * @brief Performs simulated annealing via final temperature
 * 
 * @param reduxParam The reduction parameter 
 * @param initialTemp The initial temperature
 * @param schedule May either be [1] Linear Schedule, [2] Geometric Schedule, [3] Slow Decrease
 * @param solution The initial solution set 
 */
void calcFinalTemp(float reduxParam, float initialTemp, char schedule, std::deque<float> solution){
	float finalTemp = setFinalTemp(initialTemp);
	float ofv_solution, ofv_new_solution, delta_f, probability, z;
	std::deque<float> newSolution;
	while(initialTemp > finalTemp){
		std::cout << "Temperature: " << initialTemp << std::endl;
		std::cout << "Object Function Value is: " << griewank(solution) << "\n\n";

		newSolution = generateSeries(false);

		ofv_solution = griewank(solution);
		ofv_new_solution = griewank(newSolution);

		delta_f = ofv_new_solution - ofv_solution;

		if(delta_f < 0){
			solution = newSolution;
		}else {
			probability = getProbability(delta_f, initialTemp);
			z = griewankGenerate(0,1);
			if(z < probability){
				solution = newSolution;
			}
		}

		initialTemp = changeTemp(schedule, initialTemp, reduxParam);
	}

	std::cout << "Final Solution: " << griewank(solution) << std::endl;
	std::cout << "Solution set: [ ";
	for(float val: solution){
		std::cout << val << " ";
	}
	std::cout << "]";
}