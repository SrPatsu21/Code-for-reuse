#ifndef ECO_HPP
#define ECO_HPP

#include "PlayMusic.hpp"

class Eco : public PlayMusic
{
private:
    PlayMusic* playm;
public:
    Eco(PlayMusic* playm);
    ~Eco();
    virtual void play(); 
};

#endif