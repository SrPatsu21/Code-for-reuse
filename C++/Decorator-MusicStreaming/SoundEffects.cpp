#include "SoundEffects.hpp"

SoundEffects::SoundEffects(PlayMusic* playm)
{
    this->playm = playm;
};

SoundEffects::~SoundEffects()
{

};

void SoundEffects::play()
{
    playm->play();
    std::cout << "SoundEffects" << std::endl;
}