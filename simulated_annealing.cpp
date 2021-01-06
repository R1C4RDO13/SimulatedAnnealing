#include "simulated_annealing.h"

#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Solution.h"

#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <vector>

bool simulated_annealing::random_bool()
{
    if (rand() % 2)
    {
        return true;
    }
    return false;
}

simulated_annealing::simulated_annealing()
{
	unsigned yes = 0, no = 0;
    double probTemp = 0;
    srand(time(NULL));

	//generate random first solution
    std::vector<Item> items
	{//value , weight , ispresent in initial solution 
		{10, 9, this->random_bool()},
		{12, 29, this->random_bool()},
		{13, 2,  this->random_bool()},
		{20, 23, this->random_bool()},
		{5,  12, this->random_bool()},
		{22, 32, this->random_bool()},
		{4,  14, this->random_bool()}
	};
	Solution currentSolution(items);//random

     double current_temperature = k_initial_temperature;

    std::ofstream csv("results.csv", std::ofstream::out);
    double currentTemperature = k_initial_temperature;
    for (unsigned i = 0; i < k_times_to_decrease_temperature; i++)
    {
        std::cout << std::endl << "-------------------------Temperature = " << currentTemperature << std::endl;
        std::cout << "Solution = " << currentSolution.toString() << std::endl;
        for (unsigned j = 0; j < k_neighbors; j++)
        {
            Solution candidate = currentSolution.randomWalk();
            std::cout << "Candidate = " << candidate.toString() << std::endl;
            if (candidate.value() > currentSolution.value())// notice inverted sign
            {
                std::cout << "Found a better solution" << std::endl;
                currentSolution = candidate;
            }
            else if(candidate.value()>0)
            {
                double frac =  - candidate.value() + currentSolution.value();//notice inverted sign
                double probability = 1 / exp(frac/currentTemperature);

                std::cout << "Probability = " << probability << std::endl;
                probTemp = probability;

                double r = (double)(rand() % 1000) / 1000;

                if (r < probability)
                {
                    std::cout << "Taking the worse solution" << std::endl;
                    currentSolution = candidate;
                    yes++;
                }
                else
                {
                    std::cout << "NOT taking the worse solution" << std::endl;
                    no++;
                }
            }
        }
        std::cout << " Worse solution? Yes " << yes << " No " << no << std::endl;
        currentTemperature = currentTemperature * k_decrease_amount;
        csv << currentSolution.value() << "\t" << yes << "\t" << no << "\t" << probTemp << '\n';
    }
    std::cout << "Finally, solution = " << currentSolution.toString() << std::endl;
    csv.close();

}
