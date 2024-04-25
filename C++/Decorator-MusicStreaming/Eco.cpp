#include "Eco.hpp"

Eco::Eco(PlayMusic* playm)
{
    this->playm = playm;
};

Eco::~Eco()
{

};

void Eco::play()
{
    playm->play();
    std::cout << "eco" << std::endl;
}