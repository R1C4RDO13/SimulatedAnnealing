#include "Solution.h"

#include <iostream>
#include <sstream>

Solution::Solution(std::vector<Item> items) : mItems{ items }
{
}


std::string Solution::toString() const
{
	std::ostringstream stream;
	stream << "Items: ";
	for (Item const& i : mItems)
	{
		stream << i.toString() << " ";
	}
	stream << std::endl << " Total weight & value = " << getTotalWeight() << ' ' << value() << std::endl;

	return stream.str();
}

double Solution::getTotalWeight() const
{
    double weightSum{ 0 };
    for (Item const& i : mItems)
    {
        if (i.isPresent())
            weightSum += i.getWeight();
    }
    return weightSum;
}
double Solution::value() const
{
    double valueSum{ 0 };
    for (Item const& i : mItems)
    {
        if (i.isPresent())
            valueSum += i.getValue();
    }
    if (getTotalWeight() > kMaxWeight)
    {
        return -10; //invalid solution
    }
    return valueSum;
}
// 1. penalty
// 2. discard
// 3. repair

Solution Solution::randomWalk() const
{
    std::vector<Item> itemsCopy = this->mItems;
    unsigned index = rand() % itemsCopy.size();

    itemsCopy[index].setPresent(1 - itemsCopy[index].isPresent());

    Solution newSolution(itemsCopy);
    while (newSolution.value() < 0)
    {
        for (Item& i : itemsCopy)
        {
            if (i.isPresent())
            {
                i.setPresent(false);
                break;
            }
        }
        newSolution.mItems = itemsCopy;
    }

    return newSolution;
}
