#include <iostream>
#include "structures.h"

float alpha();
float beta();
char termCriterion();
float griewank_generate(float lb, float ub);
list *num_series(int dimension);
float griewank(list *solution);
float prob_density(float delta_f, float T);
list *newNode(float num);
void empty(list **solution);
int length(list *solution);


