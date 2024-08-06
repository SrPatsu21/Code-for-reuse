#include "./AbstractCharacter.hpp"

AbstractCharacter::AbstractCharacter(int maxlife, int life, int damage, int level)
 : AbstractLivingEntity(maxlife, life, damage, level)
{
    this->item = NULL;
}

AbstractCharacter::~AbstractCharacter(){}

void AbstractCharacter::passBout()
{
    AbstractLivingEntity::passBout();    
}

void AbstractCharacter::atackEnemy(AbstractLivingEntity * enemy)
{
    if (getItem() == NULL)
    {
        enemy->receiveDamage(getDamage(), getLevel());
    }else
    {
        enemy->receiveDamage(getDamage() + getItem()->getDamage(), getLevel());
    }
}

AbstractUsableItens* AbstractCharacter::getItem()
{
    return this->item;
};
void AbstractCharacter::setItem(AbstractUsableItens* item)
{
    this->item = item;
    if (this->item != NULL)
    {  
        item->setAsTaked();
        item->setOwner(this);
    }

};
void AbstractCharacter::useItem()
{
    if (getItem() != NULL)
    {
            getItem()->useItem();
    }
};