#include "./AbstractUsableItens.hpp"

AbstractUsableItens::AbstractUsableItens(int durability, int damage)
: AbstractTakeOnceItem()
{
    setDurability(durability);
    setDamage(damage);
}
AbstractUsableItens::AbstractUsableItens(int durability, int damage, AbstractCharacter* own)
: AbstractTakeOnceItem(true, own)
{
    setDurability(durability);
    setDamage(damage);
}


AbstractUsableItens::~AbstractUsableItens()
{
    if (this->durability == 0)
    {
        std::cout << "player broak the item"<< std::endl;
    }
}
void AbstractUsableItens::setDurability(int durability=1)
{
    this->durability = durability;
};
void AbstractUsableItens::reduceDurability()
{
    reduceDurability(1);
};
void AbstractUsableItens::reduceDurability(int amout)
{
    this->durability -= amout;
    if(getDurability() == 0)
    {
        getOwner()->setItem(NULL);
        delete this;
    }
};
int AbstractUsableItens::getDurability()
{
    return this->durability;
};
void AbstractUsableItens::setDamage(int damage=0)
{
    this->damage = damage;
};
int AbstractUsableItens::getDamage()
{
    return this->damage;
};
void AbstractUsableItens::useItem()
{
};