#include "./AbstractMobs.hpp"

AbstractMobs::AbstractMobs(int maxlife, int life, int damage, int level)
: AbstractLivingEntity(maxlife, life, damage, level)
{
}

// AbstractMobs::~AbstractMobs()
// {
//     AbstractLivingEntity::~AbstractLivingEntity();
// }

void AbstractMobs::passBout()
{
    AbstractLivingEntity::passBout();
}