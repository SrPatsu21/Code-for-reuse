#include "./AbstractEntity.hpp"

AbstractEntity::AbstractEntity()
{
    this->bout = 0;
}

AbstractEntity::~AbstractEntity()
{}

int AbstractEntity::getBout()
{
    return bout;
}
void AbstractEntity::passBout()
{
    this->bout++;
}