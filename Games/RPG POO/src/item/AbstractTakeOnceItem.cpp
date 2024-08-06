#include "AbstractTakeOnceItem.hpp"
#include "../entity/AbstractCharacter.hpp"

AbstractTakeOnceItem::AbstractTakeOnceItem()
{
    setAsUntaked();
    removeOwner();
}
AbstractTakeOnceItem::AbstractTakeOnceItem(bool taked, AbstractCharacter* own)
{
    setAsTaked();
    setOwner(own);
};

AbstractTakeOnceItem::~AbstractTakeOnceItem(){}

bool AbstractTakeOnceItem::isTaked()
{
    return this->taked;
};

void AbstractTakeOnceItem::setAsTaked()
{
    this->taked = true;
};

void AbstractTakeOnceItem::setAsUntaked()
{
    this->taked = false;
};

void AbstractTakeOnceItem::setOwner(AbstractCharacter* own)
{
    this->owner = own;
};
void AbstractTakeOnceItem::removeOwner()
{
    this->owner = 0;
};

AbstractCharacter* AbstractTakeOnceItem::getOwner()
{
    return owner;
};