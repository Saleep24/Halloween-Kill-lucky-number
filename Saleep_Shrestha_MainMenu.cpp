/*
Name: Saleep Shrestha
Student_ID: w10167735
Program Description: Main menu implementation for the Last Person Alive simulation.
*/

#include "Saleep_Shrestha_Simulation.h"
#include <iostream>
#include <vector>
#include <limits> 

using namespace std;

void RunSimulation() {
    int numPeople;

    // Input validation for number of people
    while (true) {
        cout << "Enter the number of people: ";
        cin >> numPeople;

        // Check if input is valid
        if (cin.fail() || numPeople <= 0) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a positive integer.\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            break; 
        }
    }

    vector<string> people(numPeople);
    cout << "Enter the names of the people:\n";
    for (int i = 0; i < numPeople; ++i) {
        cout << "Person " << (i + 1) << ": ";
        cin >> people[i];
    }

    int skip;

    // Input validation for skip number
    while (true) {
        cout << "Enter the magic number (skip number): ";
        cin >> skip;

        // Check if input is valid
        if (cin.fail() || skip <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Invalid input. Please enter a positive integer for the skip number.\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            break;
        }
    }

    Simulation simulation;
    simulation.RunNewSimulation(people, skip);

    cout << "Elimination order:\n";
    vector<string> eliminationList = simulation.GetEliminationList();
    for (size_t i = 0; i < eliminationList.size(); ++i) {
        cout << eliminationList[i] << " was eliminated.\n";
    }

    cout << "Survivor: " << simulation.GetSurvivor() << endl;
}


int main() {
    char choice;
    do {
        RunSimulation();
        
        // Ask the user if they want to run another simulation
        cout << "Would you like to run another simulation? (y/n): ";
        cin >> choice;

        // Validate input
        while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N') {
            cout << "Invalid input. Please enter 'y' or 'n': ";
            
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cin >> choice;
        }
        
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
