/*
Name: Saleep Shrestha
Student_ID: w10167735
Program Description: This file defines the Simulation class which inherits from Queue and simulates the last person alive scenario.
*/

#ifndef SALEEP_SHRESTHA_SIMULATION_H
#define SALEEP_SHRESTHA_SIMULATION_H

#include "Saleep_Shrestha_Queue.h"
#include <vector>

class Simulation : private Queue {
private:
    vector<string> eliminated;
    string survivor;
    int skip_number;

    void RunSimulation() {
    // Ensure we have at least one person
    if (GetCount() == 0) {
        return;
    }

    while (GetCount() > 1) {
        for (int i = 0; i < skip_number - 1; ++i) {
            string person;
            Dequeue(person);  
            Enqueue(person);   
        }
        
        // Eliminate the next person
        string eliminatedPerson;
        if (Dequeue(eliminatedPerson)) { // Only eliminate if there's someone to eliminate
            eliminated.push_back(eliminatedPerson);
        }
    }

    Dequeue(survivor); // Get the last person
}

public:
    Simulation() : skip_number(0) {}

    void RunNewSimulation(const vector<string>& people, int skip) {
    eliminated.clear();
    survivor.clear();
    skip_number = skip;


    while (GetCount() > 0) {
        string dummy;
        Dequeue(dummy);
    }
    

    for (size_t i = 0; i < people.size(); ++i) {
        Enqueue(people[i]);
    }

    RunSimulation(); 
}


    vector<string> GetEliminationList() const {
        return eliminated;
    }

    string GetSurvivor() const {
        return survivor;
    }
};

#endif
