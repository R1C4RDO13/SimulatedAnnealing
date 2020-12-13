#pragma once

#include <string>

class Solution
{
public:
	Solution();
	Solution(double _x, double _y);
	std::string to_string() const;
	double value() const;
	Solution random_walk(double max_step) const;

private:
	double x, y;

};

