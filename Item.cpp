#include "Item.h"
#include <sstream>

Item::Item(double value, double weight, bool isPresent) : mValue(value) , mWeight(weight) , mIsPresent(isPresent)
{
}

double Item::getValue() const
{
    return mValue;
}
double Item::getWeight() const
{
    return mWeight;
}

bool Item::isPresent() const
{
    return mIsPresent;
}

void Item::setPresent(bool newValue) { mIsPresent = newValue; }


std::string Item::toString() const
{
    std::ostringstream stream;
    stream << "w = " << mWeight << " v = " << mValue << " p = " << mIsPresent;
    return stream.str();
}
