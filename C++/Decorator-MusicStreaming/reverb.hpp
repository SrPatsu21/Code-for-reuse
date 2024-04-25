#ifndef REVEB_HPP
#define REVEB_HPP

#include "PlayMusic.hpp"

class Reverb : public PlayMusic
{
private:
    PlayMusic* playm;
public:
    Reverb(PlayMusic* playm);
    ~Reverb();
    virtual void play(); 
};

#endif