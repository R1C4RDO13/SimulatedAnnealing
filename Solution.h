#pragma once

#include <string>
#include "Item.h"
#include <vector>
class Solution
{
public:
	Solution(std::vector<Item> items);
	std::string toString() const;
	double value() const;
	Solution randomWalk() const;

private:
	double getTotalWeight() const;
	std::vector<Item> mItems;
	static const unsigned kMaxWeight = 100;//TODO: set it by user input 

};

