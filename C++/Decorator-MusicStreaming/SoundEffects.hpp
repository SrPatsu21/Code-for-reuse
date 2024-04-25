#ifndef SOUNDEFFECTS_HPP
#define SOUNDEFFECTS_HPP

#include "PlayMusic.hpp"

class SoundEffects : public PlayMusic
{
private:
    PlayMusic* playm;
public:
    SoundEffects(PlayMusic* playm);
    ~SoundEffects();
    virtual void play(); 
};

#endif