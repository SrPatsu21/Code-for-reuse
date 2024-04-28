#ifndef REVEB_HPP
#define REVEB_HPP

#include "BaseDecorator.hpp"

class Reverb : public BaseDecorator
{
public:
    Reverb(PlayMusic* playm);
    ~Reverb();
    virtual void play(); 
};

#endif