#ifndef Hammer_hpp
#define Hammer_hpp
#include "../AbstractUsableItens.hpp"

class Hammer : public AbstractUsableItens
{
public:
    Hammer();
    ~Hammer();
    void useItem();
};

#endif