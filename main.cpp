#include <iostream>
#include <cctype>
#include <stdlib.h>
#include <limits>
#include <string>
#include <ios>

int main(){
    int stopper = 0;
    char schedule;

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
        switch (toupper(schedule)) {
            case 'a':
                stopper = 1;
                break;
            case 'b':
                ProgDescription(); // Goes to the function that explains briefly what the program does
                stopper = 0;
                break;
            case 'c':
                InfixPostfix(); // Turns expression to postfix and evaluates it
                stopper = 0;
                break;
            default: // Runs if user entered an invalid input
                stopper = 0;
                printf("Invalid input.\n"); //Prints message if user inputs a value other than the ones indicated in the menu
        }
        
    }
    return 0;
}
