#pragma once
#include <iostream>
#include <deque>
#include <utility>

float setTempReduxParam(bool isAlpha);
bool setTermCriterion();
std::pair<int,int> setTrialsAndCycles();
float setInitialTemp();
float setFinalTemp(float initialTemp);