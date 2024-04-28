#include "Reverb.hpp"

Reverb::Reverb(PlayMusic* playm): BaseDecorator(playm)
{
};

Reverb::~Reverb()
{

};

void Reverb::play()
{
    playm->play();
    std::cout << "Reverb" << std::endl;
}