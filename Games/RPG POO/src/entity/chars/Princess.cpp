#include "Princess.hpp"

Princess::Princess()
 : AbstractCharacter(10, 10, 4, 3)
{}

Princess::~Princess()
{
    AbstractCharacter::~AbstractCharacter();
}