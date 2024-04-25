#include "Equalize.hpp"

Equalize::Equalize(PlayMusic* playm)
{
    this->playm = playm;
};

Equalize::~Equalize()
{

};

void Equalize::play()
{
    playm->play();
    std::cout << "Equalize" << std::endl;
}