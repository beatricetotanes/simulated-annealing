#include <iostream>
#include "helper.h"
#include <cstdlib>
#include <cmath>
#include <time.h>

using namespace std;

float alpha(){
    float alpha;
    cout << "\t\nSpecify value of alpha: "; 
    cin >> alpha;
    return alpha;
}

float beta(){
    float beta;
    cout << "\t\nSpecify value of beta: "; 
    cin >> beta;
    return beta;
}

char termCriterion(){
    char choice;
    int stopper = 0;

    while (stopper==0)
    {
        cout << "\nChoose which termination criterion to use\n";
        cout << "\t[a] Max trials and cycles\n";
        cout << "\t[b] When temperature reaches final temperature\n";
        cout << "\nChoice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.clear();
        
        switch (tolower(choice))
        {
            case 'a': // Max trials and cycles
                stopper = 1;
                break;
            case 'b': // Temperature
                stopper = 1;
                break;
            default:
                stopper = 0;
                printf("Invalid input. Try again.\n"); //Prints message if user inputs a value other than the ones indicated in the menu
                break;
        }
    }

    return choice;
}

list *newNode(float num){
    list *newnode = new list; //allocating memory for the new node
    newnode->num = num;
    newnode->next = NULL;
    
    return newnode; //returns new node
}

int length(list *solution){
    list *temp = solution;
    int ctr = 0;

    while (temp != NULL)
    {
        ctr++;
        temp = temp->next;
    }
    return ctr;
}

// generates random numbers
float griewank_generate(float lb, float ub){
    float ans; 
    ans = ((float)rand()/(float)RAND_MAX)*(ub - lb);
    return lb + ans;
}

float griewank(list *solution){
    float summation = 0.0;
    float product = 1.0;
    int i;
    int len = length(solution);

    for (i = 0; i < len; i++)
    {   
        summation = summation + (solution->num * solution->num)/4000;
        product = product * cos(solution->num/sqrt(i+1));
        solution = solution->next;
    }

    return summation - product + 1;
    
}
float prob_density(float delta_f, float T){
    return exp(-1 * delta_f/T);
}

void empty(list **solution){
    list *tmp = *solution;
    while (*solution != NULL)
    {   
        *solution= (*solution)->next; //Moves the top position to the next node after the first node
        delete tmp;
    }
    
};

list *num_series(int dimension){
    int i;
    list *solution = NULL;
    list *tmp;
    
    for (i = 0; i < dimension; i++)
    {
        if (solution == NULL)
        {
            solution = newNode(griewank_generate(-5.0, 5.0));
        }else{
            tmp = solution;
            while (tmp->next != NULL)
            {
                tmp = tmp->next;
            }

            tmp->next = newNode(griewank_generate(-5.0, 5.0));
            
        }
    }

    return solution;
    
}



