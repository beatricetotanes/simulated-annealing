#include <iostream>
#include <cstdlib>
#include <cmath>
#include <time.h>
#include "calculations.h"

using namespace std;

float init_temp(){
    float temp;

    cout << "Enter initial temperature: ";
    cin >> temp;

    return temp; 
}

trials_cycles max_trials_cycles(){
    trials_cycles temp;

    cout << "\nEnter no. of trials: ";
    cin >> temp.trials;
    cout << "\nEnter no. of cycles: ";
    cin >> temp.cycles;

    return temp;
}

float linear(float alpha, char termination, list *solution){
    trials_cycles basis;
    float initial_temp = init_temp();
    float final_temp;
    int K, k;

    switch (termination)
    {
    case 'a': // max trials and cycles
        basis = max_trials_cycles();
        for (K = 0; K < basis.cycles; K++)
        {
            cout << "Cycle: " << K << "Temperature: " << initial_temp;
            cout << "Obj Func Value is: " << griewank(solution);
            for (k = 0; k < basis.trials; k++)
            {
                /* code */
            }
            
        }
        
        break;
    case 'b': // temperatures
        cout << "\nEnter Final Temperature: ";
        cin >> final_temp;
        break;
    default:
        break;
    }
}
float geometric(float alpha, char termination, list *solution);
float slow_decrease(float beta, char termination, list *solution);
