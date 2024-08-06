#include "Hero.hpp"

Hero::Hero()
 : AbstractCharacter(10, 10, 4, 3)
{}

Hero::~Hero()
{
    AbstractCharacter::~AbstractCharacter();
}