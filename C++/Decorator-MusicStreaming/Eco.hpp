#ifndef ECO_HPP
#define ECO_HPP

#include "BaseDecorator.hpp"

class Eco : public BaseDecorator
{
public:
    Eco(PlayMusic* playm);
    ~Eco();
    virtual void play(); 
};

#endif