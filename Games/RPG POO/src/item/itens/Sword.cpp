#include "./Sword.hpp"
#include <iostream>

Sword::Sword()
:AbstractUsableItens(10 , 2)
{
}

Sword::~Sword()
{
}

void Sword::useItem()
{
    std::cout << "nada aconteceu" << std::endl;
    reduceDurability();
};