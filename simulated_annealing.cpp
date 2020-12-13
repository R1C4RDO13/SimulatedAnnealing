#include "simulated_annealing.h"

#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Solution.h"

simulated_annealing::simulated_annealing()
{

    double probTemp = 0;
    srand(time(NULL));

    Solution current_solution; //inital random solution

     double current_temperature = k_initial_temperature;

	
	for (unsigned i = 0 ; i< k_times_to_decrease_temperature ; i ++ )
	{
		unsigned yes = 0, no = 0;

		std::cout << "------------- ---------- Temperature = " << current_temperature << std::endl;
		std::cout << "Current Solution " << current_solution.to_string() << std::endl;

		//for each temperature we need to walk around the neighborhood 
		for(unsigned j = 0 ; j < k_neighbors ; j++)
		{
			Solution candidate = current_solution.random_walk(k_step);
			std::cout << "Candidate Solution " << candidate.to_string() << std::endl;
			if (candidate.value() < current_solution.value()) //this is to minimize, the lower the values better is
			{
				std::cout << "Better solution found" << std::endl;
				current_solution = candidate;
			}
			else //check if takes worst solution
			{
				//
				double frac = candidate.value() - current_solution.value();
				double probability = 1 / exp(frac / current_temperature); //probability of taking worst solution

				std::cout << "Probability " << probability << std::endl;
				//			this cast is actually important 
				auto r =  (double)(rand() % 1000) / 1000; // 0 to 0.9999
				if (r < probability)
				{
					std::cout << "Taking worst solution " << std::endl;
					current_solution = candidate;
					yes++;
				}
				else
				{
					std::cout << "Not taking worst solution " << std::endl;
					no++;
				}
				
				
				
			}
		}

		std::cout << " Worse solution? Yes " << yes << " No " << no << std::endl;

		current_temperature = current_temperature * k_decrease_amount;
	}
	std::cout << "Finally, solution = " << current_solution.to_string() << std::endl;

}
