#ifndef EQUALIZE_HPP
#define EQUALIZE_HPP

#include "PlayMusic.hpp"

class Equalize : public PlayMusic
{
private:
    PlayMusic* playm;
public:
    Equalize(PlayMusic* playm);
    ~Equalize();
    virtual void play(); 
};

#endif