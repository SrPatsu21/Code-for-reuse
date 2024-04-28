#include "Eco.hpp"

Eco::Eco(PlayMusic* playm): BaseDecorator(playm)
{

};

Eco::~Eco()
{

};

void Eco::play()
{
    playm->play();
    std::cout << "eco" << std::endl;
}