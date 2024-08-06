#include "./Hammer.hpp"

Hammer::Hammer()
:AbstractUsableItens(10 , 1)
{
}

Hammer::~Hammer()
{
}

void Hammer::useItem()
{
    getOwner()->lifeRegen(10);
    reduceDurability();
};