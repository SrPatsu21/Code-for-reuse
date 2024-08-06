#ifndef Sword_hpp
#define Sword_hpp
#include "../AbstractUsableItens.hpp"

class Sword : public AbstractUsableItens
{
public:
    Sword();
    ~Sword();
    void useItem();
};

#endif