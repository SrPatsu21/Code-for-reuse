#ifndef AbstractUsableItens_hpp
#define AbstractUsableItens_hpp

#include "./AbstractTakeOnceItem.hpp"
#include "../entity/AbstractCharacter.hpp"
#include <iostream>
class AbstractCharacter;

class AbstractUsableItens : public AbstractTakeOnceItem
{
private:
    int durability;
    int damage;
protected:
    AbstractUsableItens(int durability, int damage);
    AbstractUsableItens(int durability, int damage, AbstractCharacter * owner);
public:
    ~AbstractUsableItens();

    virtual void setDurability(int durability);
    virtual void reduceDurability();
    virtual void reduceDurability(int amout);
    virtual int getDurability();
    virtual void setDamage(int damage);
    virtual int getDamage();
    virtual void useItem();
};
#endif
