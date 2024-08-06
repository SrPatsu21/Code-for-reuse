#ifndef AbstractCharacter_hpp
#define AbstractCharacter_hpp

#include "./AbstractLivingEntity.hpp"
#include "../item/AbstractUsableItens.hpp"

class AbstractUsableItens;

class AbstractCharacter : public AbstractLivingEntity
{
private:
    AbstractUsableItens* item;
protected:
    AbstractCharacter(int maxlife, int life, int damage, int level);
public:
    ~AbstractCharacter();
    
    virtual void atackEnemy(AbstractLivingEntity * enemy);
    virtual AbstractUsableItens* getItem();
    virtual void useItem();
    virtual void setItem(AbstractUsableItens * item);

    virtual void passBout();
};

#endif