#include <iostream>
#include <deque>

std::deque<float> generateSeries(bool isInitial);
float changeTemp(char schedule, float prevTemp, float reduxParam);
float griewankGenerate(float lb, float ub);
float griewank(std::deque<float> solution);
float getProbability(float delta_f, float T);
void calcTrialsCycles(float reduxParam, float initialTemp, char schedule, std::deque<float> solution);
void calcFinalTemp(float reduxParam, float initialTemp, char schedule, std::deque<float> solution);