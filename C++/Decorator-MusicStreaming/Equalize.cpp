#include "Equalize.hpp"

Equalize::Equalize(PlayMusic* playm)
: BaseDecorator(playm)
{
};

Equalize::~Equalize()
{

};

void Equalize::play()
{
    playm->play();
    std::cout << "Equalize" << std::endl;
}