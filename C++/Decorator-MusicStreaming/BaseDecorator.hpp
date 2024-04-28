#ifndef BASEDECORATOR_HPP
#define BASEDECORATOR_HPP

#include "PlayMusic.hpp"

class BaseDecorator : public PlayMusic
{
protected:
        PlayMusic* playm;
public:
    BaseDecorator(PlayMusic* playm);
    ~BaseDecorator();
    virtual void play() = 0; 
};
#endif