#pragma once
class simulated_annealing
{
public:
    const double k_initial_temperature = 100;  //initial temperature, depended on the initial problem
    const unsigned k_times_to_decrease_temperature = 100; //how many time iterating trow neighbors

    const double k_step = 1; //how far we want to look around the neighborhood --- to use in random walk
    const unsigned k_neighbors = 10;//10
    const double k_decrease_amount = 0.85;  //decrease amount in temperature 
    bool random_bool();

    simulated_annealing();

};

