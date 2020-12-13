#include "Solution.h"

#include <iostream>
#include <sstream>

Solution::Solution()
{
	//intializes the x, y values with random values
	x = rand() % 10 - 5;
	y = rand() % 10 - 5;
}

Solution::Solution(double _x, double _y) : x(_x) , y(_y)
{
}

std::string Solution::to_string() const
{
	std::ostringstream stream; // return string stream
	stream << "x = " << x << " y = " << y << " z = " << value() << std::endl;
	return  stream.str();
}

double Solution::value() const
{
	//Himmelblau
	//pow(a,b) = a^b 
	return pow((x * x) + y - 11, 2) + pow(x + (y * y) - 7, 2);
}

Solution Solution::random_walk(double max_step) const //gives us a new solution based on the current one
{ //max_step gives us the maximum difference in units from x and y 
	std::cout << "random walk " << this->to_string() << std::endl;
	double step = rand() % (2 * (int)max_step * 1000) / (double)1000;
	step = step - max_step;
	double newX = x + step;

	step = rand() % (2 * (int)max_step * 1000) / (double)1000;
	step = step - max_step;
	double newY = y + step;

	Solution newSolution(newX, newY);
	return newSolution;
	
}
