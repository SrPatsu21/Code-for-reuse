#ifndef EQUALIZE_HPP
#define EQUALIZE_HPP

#include "BaseDecorator.hpp"

class Equalize : public BaseDecorator
{
public:
    Equalize(PlayMusic* playm);
    ~Equalize();
    virtual void play(); 
};

#endif