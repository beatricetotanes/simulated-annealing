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

void compute(float redu_parameter, char termination, char schedule, list *solution){
    trials_cycles basis;
    float initial_temp = init_temp();
    float final_temp;
    list *new_solution = NULL, *tmp;
    int K, k, i;
    float ofv_solution, ofv_new_solution, delta_f;
    float probability, z;

    switch (termination)
    {
    case 'a': // max trials and cycles
        basis = max_trials_cycles();
        for (K = 0; K < basis.cycles; K++)
        {
            cout << "[Cycle: " << K << "] [Temperature: " << initial_temp << "]"<< endl;
            cout << "Obj Func Value is: " << griewank(solution) << endl << endl;
            for (k = 0; k < basis.trials; k++)
            {
                new_solution = num_series(length(solution)); // temporary till magreply si maam

                // calculate objective func values of two solutions
                ofv_solution = griewank(solution);
                ofv_new_solution = griewank(solution);

                // calculate delta f
                delta_f = ofv_new_solution - ofv_solution;

                if (delta_f < 0)
                {
                    solution = new_solution;
                }else
                {
                    probability = prob_density(delta_f, initial_temp);
                    z = griewank_generate(0, 1);
                    if (z < probability)
                    {
                        solution = new_solution;
                    }

                    // printing
                    // cout << "Solution " << k+1 << ": " << griewank(solution) << endl;
                }
            }

            switch (schedule)
            {
            case 'a': // linear
                initial_temp = initial_temp - redu_parameter; // uses alpha
                break;
            case 'b': // geometric
                initial_temp = initial_temp * redu_parameter; // uses alpha
                break;
            case 'c': // slow decrease
                initial_temp = initial_temp / (1 + redu_parameter*initial_temp); // uses beta
                break;
            default:
                break;
            }
        }

        cout << "Final Solution: " << griewank(solution) << endl;
        
        break;
    case 'b': // temperatures
        cout << "\nEnter Final Temperature: ";
        cin >> final_temp;

        while(initial_temp > final_temp)
        {
            cout << "Temperature: " << initial_temp << endl;
            cout << "Obj Func Value is: " << griewank(solution) << endl << endl;

            new_solution = num_series(length(solution)); // temporary till magreply si maam

            // calculate objective func values of two solutions
            ofv_solution = griewank(solution);
            ofv_new_solution = griewank(solution);

            // calculate delta f
            delta_f = ofv_new_solution - ofv_solution;

            if (delta_f < 0)
            {
                solution = new_solution;
            }else
            {
                probability = prob_density(delta_f, initial_temp);
                z = griewank_generate(0, 1);
                if (z < probability)
                {
                    solution = new_solution;
                }

                // printing
                // cout << "Solution " << k+1 << ": " << griewank(solution) << endl;
            }

            switch (schedule)
            {
            case 'a': // linear
                initial_temp = initial_temp - redu_parameter; // uses alpha
                break;
            case 'b': // geometric
                initial_temp = initial_temp * redu_parameter; // uses alpha
                break;
            case 'c': // slow decrease
                initial_temp = initial_temp / (1 + redu_parameter*initial_temp); // uses beta
                break;
            default:
                break;
            }
        }

        cout << "Final Solution: " << griewank(solution) << endl;
        break;
    default:
        break;
    }
}
