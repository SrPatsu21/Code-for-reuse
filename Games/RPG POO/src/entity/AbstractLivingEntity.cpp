#include "./AbstractLivingEntity.hpp"
#include <cmath>
#include <iostream>

AbstractLivingEntity::AbstractLivingEntity(int maxlife = 1, int life = 1, int damage = 0, int level = 0)
{
    this->maxlife=maxlife;
    this->life=life;
    this->damage=damage;
    this->level=level;
}

AbstractLivingEntity::~AbstractLivingEntity()
{
    std::cout << "Entity Desapier in (" << getBout() << ") Bout" << std::endl;
}

void AbstractLivingEntity::passBout()
{
    AbstractEntity::passBout();
    if(life == 0)
    {
        maxlife = 0;
    }
}
void AbstractLivingEntity::atackEnemy(AbstractLivingEntity * enemy, int damage_plus)
{
    enemy->receiveDamage(getDamage()+damage_plus, getLevel());
}
void AbstractLivingEntity::atackEnemy(AbstractLivingEntity * enemy)
{
    enemy->receiveDamage(getDamage(), getLevel());
}

void AbstractLivingEntity::receiveDamage(int damage, int enemy_level)
{
    this->life-=(int)((double)damage * ((double)enemy_level/level));
}

//encapsulation
int AbstractLivingEntity::getMaxLife()
{
    return maxlife;
}
int AbstractLivingEntity::getLife()
{
    return life;
}
int AbstractLivingEntity::getDamage()
{
    return damage;
}
int AbstractLivingEntity::getLevel()
{
    return level;
}
//handel
void AbstractLivingEntity::levelUp() 
{
    this->level++;
}
void AbstractLivingEntity::lifeRegen(int amouth)
{
    this->life = fmin(amouth + getLife(), getMaxLife());
}
void AbstractLivingEntity::lifeRegen()
{
    lifeRegen(1);
}