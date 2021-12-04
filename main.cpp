#include <iostream>
#include <cctype>
#include <limits>
#include <stdlib.h>
#include "calculations.h"

using namespace std;

int main(){
    int stopper = 0;
    char schedule;
    float reduParameter;
    char termination;
    int dimension = 5;
    list *solution = num_series(dimension);
    list *tmp = solution;

    // While user chooses not to exit the program, the program will not exit.
    while (stopper == 0) {
        //Menu
        cout << "\nChoose which temperature schedule to use\n";
        cout << "\t[a] Linear Schedule\n";
        cout << "\t[b] Geometric Schedule\n";
        cout << "\t[c] Slow Decrease\n";
        cout << "\nChoice: ";
        cin >> schedule;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.clear();

        // toupper(char) Converts the letter that the user has entered into uppercase if it is in lowercase
        switch (tolower(schedule)) {
            case 'a': // Linear
                reduParameter = alpha();
                termination = termCriterion();
                // compute(choice, termination)
                stopper = 1;
                break;
            case 'b': // Geometric
                reduParameter = alpha();
                termination = termCriterion();
                // geometric(reduParameter, termination, solution);
                stopper = 1;
                break;
            case 'c': // Slow Decrease
                reduParameter = beta();
                termination = termCriterion();
                // slow_decrease_func(reduParameter, termination, solution);
                stopper = 1;
                break;
            default: // Runs if user entered an invalid input
                stopper = 0;
                printf("Invalid input.\n"); //Prints message if user inputs a value other than the ones indicated in the menu
        }
    }

    compute(reduParameter, termination, tolower(schedule), solution);
	system("pause");
    
    return 0;
}
