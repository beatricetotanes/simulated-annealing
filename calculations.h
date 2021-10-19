#include <iostream>
#include "helper.h"

float linear(float alpha, char termination, list *solution);
float geometric(float alpha, char termination, list *solution);
float slow_decrease(float beta, char termination, list *solution);
trials_cycles max_trials_cycles();
float init_temp();