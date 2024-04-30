#ifndef SOUNDEFFECTS_HPP
#define SOUNDEFFECTS_HPP

#include "BaseDecorator.hpp"

class SoundEffects : public BaseDecorator
{
public:
    SoundEffects(PlayMusic* playm);
    ~SoundEffects();
    virtual void play(); 
};

#endif